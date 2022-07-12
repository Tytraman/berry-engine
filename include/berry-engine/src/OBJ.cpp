#include <berry-engine/OBJ.h>
#include <berry-engine/vectors.h>

#include <libcake/strutf8.h>
#include <libcake/fdio.h>

#include <string.h>

berry::Mesh berry::OBJ::load(const char *filename) {
    cake_fd fd = cake_fdio_open_file(filename, CAKE_FDIO_ACCESS_READ, CAKE_FDIO_SHARE_READ, CAKE_FDIO_OPEN_IF_EXISTS, CAKE_FDIO_ATTRIBUTE_NORMAL);
    if(fd == CAKE_FDIO_ERROR_OPEN)
        return Mesh();

    Cake_String_UTF8 *content = cake_strutf8("");
    cake_fdio_mem_copy_strutf8(content, fd, 2048);
    cake_fdio_close(fd);

    Cake_String_UTF8_Reader reader;
    cake_create_strutf8_reader_utf(&reader, content);
    Cake_String_UTF8 *line;
    Cake_List_String_UTF8 *sub;
    Cake_List_String_UTF8 *f;
    char decSep = '.';
    ulonglong i;

    ArrayList<Vec3> vertexPositions;
    ArrayList<Vec2> texCoords;
    ArrayList<Vec3> normalPositions;

    ArrayList<uint> vertexIndices;
    ArrayList<uint> texCoordsIndices;
    ArrayList<uint> normalIndices;

    while((line = cake_strutf8_readline(&reader))) {
        sub = cake_strutf8_split(line, " ");

        // Vertices
        if(cake_strutf8_equals(sub->list[0], "v")) {
            if(sub->data.length > 3) {
                vertexPositions.push(Vec3(
                    cake_strutf8_to_float(sub->list[1], decSep),
                    cake_strutf8_to_float(sub->list[2], decSep),
                    cake_strutf8_to_float(sub->list[3], decSep)
                ));
            }
        }

        // Textures UV
        else if(cake_strutf8_equals(sub->list[0], "vt")) {
            if(sub->data.length > 2) {
                texCoords.push(Vec2(
                    cake_strutf8_to_float(sub->list[1], decSep),
                    cake_strutf8_to_float(sub->list[2], decSep)
                ));
            }
        }

        // Normals
        else if(cake_strutf8_equals(sub->list[0], "vn")) {
            if(sub->data.length > 3) {
                normalPositions.push(Vec3(
                    cake_strutf8_to_float(sub->list[1], decSep),
                    cake_strutf8_to_float(sub->list[2], decSep),
                    cake_strutf8_to_float(sub->list[3], decSep)
                ));
            }
        }

        // Faces
        else if(cake_strutf8_equals(sub->list[0], "f")) {
            for(i = 1; i < sub->data.length; ++i) {
                f = cake_strutf8_split(sub->list[i], "/");

                // TODO: gérer les autres cas de figure
                if(f->data.length > 2) {
                    vertexIndices.push(cake_strutf8_to_ulonglong(f->list[0]) - 1);
                    texCoordsIndices.push(cake_strutf8_to_ulonglong(f->list[1]) - 1);
                    normalIndices.push(cake_strutf8_to_ulonglong(f->list[2]) - 1);
                }
                cake_free_list_strutf8(f);
            }
        }

        cake_free_list_strutf8(sub);
        cake_free_strutf8(line);
    }

    cake_free_strutf8(content);

    return Mesh(
        vertexPositions,
        texCoords,
        normalPositions,
        vertexIndices,
        texCoordsIndices,
        normalIndices
    );
}
