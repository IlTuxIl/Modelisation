//
// Created by julien on 17/10/17.
//

#include <Render.h>
#include <window.h>
#include <program.h>
#include <uniforms.h>

namespace GeoLib {

    Render::Render(std::vector<Maillage*> _mesh, std::vector<Color> _c){
        mesh = _mesh;
        c = _c;
        program = read_program("data/shader1.glsl");
        initBuffer();
        glUseProgram(0);
    }

    void Render::draw(Orbiter cam, bool update, std::vector<bool> affiche) {

        if(update)
            updateBuffer();

        Transform MVP = cam.projection(window_width(), window_height(), 45) * cam.view() * Identity();

        for(int i = 0; i < mesh.size(); i++){
            if(affiche[i]){
                glBindVertexArray(vao[i]);
                glUseProgram(program);

                program_uniform(program, "mvpMatrix", MVP);
                program_uniform(program, "color", c[i]);

                if(mesh[i]->getNbIndiceFace() == 2)
                    glDrawElements(GL_LINES, mesh[i]->getIndice().size(), GL_UNSIGNED_INT, 0);
                else if(mesh[i]->getNbIndiceFace() == 3)
                    glDrawElements(GL_TRIANGLES, mesh[i]->getIndice().size(), GL_UNSIGNED_INT, 0);

                glBindVertexArray(0);
                glUseProgram(0);
            }
        }
    }

    void Render::initBuffer() {

        for(int i = 0; i < mesh.size(); i++){
            unsigned int sizeBuffer = mesh[i]->getVertexBufferSize();
            unsigned int offset= 0;

            vao.push_back(GLuint());
            glGenVertexArrays(1, &vao[i]);
            glBindVertexArray(vao[i]);

            buffer.push_back(GLuint());
            glGenBuffers(1, &buffer[i]);
            glBindBuffer(GL_ARRAY_BUFFER, buffer[i]);
            glBufferData(GL_ARRAY_BUFFER, sizeBuffer, nullptr, GL_STATIC_DRAW);

            std::cout << offset << " " << sizeBuffer << std::endl;

            glBufferSubData(GL_ARRAY_BUFFER, offset, sizeBuffer, &mesh[i]->getVertex()[0]);
            glVertexAttribPointer(0, 3, GL_FLOAT, GL_FALSE, 0, (const void *) offset);
            glEnableVertexAttribArray(0);

            indexBuffer.push_back(GLuint());
            sizeBuffer = mesh[i]->getIndiceBufferSize();
            glGenBuffers(1, &indexBuffer[i]);
            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[i]);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, sizeBuffer, &mesh[i]->getIndice().front(), GL_STATIC_DRAW);
        }

        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Render::updateBuffer() {

        for(int i = 0; i < mesh.size(); i++){
            size_t sizeBuffer = mesh[i]->getVertexBufferSize();
            size_t offset= 0;

            glBindVertexArray(vao[i]);
            glBindBuffer(GL_ARRAY_BUFFER, buffer[i]);

            glBufferData(GL_ARRAY_BUFFER, sizeBuffer, nullptr, GL_DYNAMIC_DRAW);
            glBufferSubData(GL_ARRAY_BUFFER, offset, sizeBuffer, &mesh[i]->getVertex()[0]);

            glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, indexBuffer[i]);
            glBufferData(GL_ELEMENT_ARRAY_BUFFER, mesh[i]->getIndiceBufferSize(), &mesh[i]->getIndice().front(), GL_DYNAMIC_DRAW);
        }

        glBindVertexArray(0);
        glBindBuffer(GL_ELEMENT_ARRAY_BUFFER, 0);
        glBindBuffer(GL_ARRAY_BUFFER, 0);
    }

    void Render::destroy() {
        for(int i = 0; i < mesh.size(); i++){
            glDeleteVertexArrays(1, &vao[i]);
            glDeleteBuffers(1, &buffer[i]);
            glDeleteBuffers(1, &indexBuffer[i]);
        }
    }

}
