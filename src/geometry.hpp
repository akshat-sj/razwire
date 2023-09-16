#ifndef GEOMETRY_HPP
#define GEOMETRY_HPP
#include <cstdlib>
#include <filesystem>
#include <fstream>
#include <iostream>
#include <set>
#include <sstream>
#include <string>
#include <tuple>
#include <vector>
#include <string.h>

typedef std::tuple<float, float, float>Vertex;
typedef std::tuple<uint32_t, uint32_t> Edge;

class Model{
    public:
    std::string model_name;
    std::vector<Vertex> vertices;
    std::set<Edge> edges;
    Model loadobj(std::string name){
    Model model;
    std::ifstream objfile(name);
    std::string line;
    std::vector<Edge> edges;
    while(std::getline(objfile,line)){
        std::string linetype;
        std::stringstream lineStream(line);
        std::getline(lineStream, linetype, ' ');
        if (linetype == "o") {
            lineStream >> model.model_name;
        } 
        if (linetype == "v") {
            float x, y, z;
            lineStream >> x >> y >> z;
            model.vertices.push_back({x,-y, z});
        } 
        if (linetype == "f") {
            std::string coords;
            int firstFace = -1;
            int lastFace;
            while (std::getline(lineStream,coords,' ')) {
                int faceIndex = atoi(strtok(const_cast<char*>(coords.c_str()), "/")) - 1;
                if (firstFace == -1) {
                    firstFace = faceIndex;
                } else {
                    int a = std::min(lastFace, faceIndex);
                    int b = std::max(lastFace, faceIndex);
                    if (a != b) model.edges.insert({a, b});
                }
                lastFace = faceIndex;
            }
            int a = std::min(lastFace, firstFace);
            int b = std::max(lastFace, firstFace);
            if (a != b)
            {
                model.edges.insert({a, b});
            }
            }
        }
        return model;
    }
    private:

};
#endif