#include "curve_io.h"

#include <sstream>
#include <iostream>
#include <fstream>

namespace LWS {
    namespace CurveIO {

        using namespace std;

        std::vector<std::string> split(const std::string& s, char delimiter) {
            vector<string> tokens;
            string token;
            istringstream tokenStream(s);
            while (std::getline(tokenStream, token, delimiter))
            {
                tokens.push_back(token);
            }
            return tokens;
        }

        void readVerticesAndEdges(std::string fname, std::vector<Vector3> &all_positions,
        std::vector<std::array<size_t, 2>> &all_edges) {
            
            ifstream myfile(fname);
            string line;

            while (getline(myfile, line))
            {
                vector<string> tokens = split(line, ' ');
                if (tokens[0] == "v") {
                    Vector3 v{stod(tokens[1]), stod(tokens[2]), stod(tokens[3])};
                    all_positions.push_back(v);
                }
                else if (tokens[0] == "l") {
                    // Minus 1 because objs are 1-indexed
                    size_t v1 = stoul(tokens[1]) - 1;
                    size_t v2 = stoul(tokens[2]) - 1;
                    all_edges.push_back({v1, v2});
                }
            }
            myfile.close();

            std::cout << "Read " << all_positions.size() << " vertices, " << all_edges.size() << " edges" << std::endl;
        }

        void readFaces(std::string fname, std::vector<std::array<size_t, 2>> &all_edges) {
            ifstream myfile(fname);
            string line;

            while (getline(myfile, line))
            {
                vector<string> tokens = split(line, ' ');
                vector<unsigned long> indices;

                if (tokens[0] == "f") {
                    // Get all the indices into a list
                    for (size_t i = 1; i < tokens.size(); i++) {
                        indices.push_back(stoul(tokens[i]) - 1);
                    }
                }
                for (size_t i = 0; i < indices.size(); i++) {
                    size_t i_next = (i + 1) % indices.size();
                    all_edges.push_back({indices[i], indices[i_next]});
                }
            }
            myfile.close();

            std::cout << "Read " << all_edges.size() << " edges from faces" << std::endl;

        }

        void writeOBJLineElements(std::string fname, const std::vector<Vector3> &all_positions,
        const std::vector<std::vector<size_t> > &components) {

            ofstream myfile(fname);

            // write vertices
            for(const Vector3& v : all_positions) {
                myfile << "v " << v.x << " " << v.y << " " << v.z << endl;
            }

            // write polylines
            for(const auto& c : components) {
                myfile << "l";
                for( size_t i : c ) {
                    myfile << " " << (1+i);
                }
                myfile << endl;
            }
            myfile.close();

            std::cout << "Wrote " << all_positions.size() << " vertices, " << components.size() << " polylines" << std::endl;
        }
    }
}

