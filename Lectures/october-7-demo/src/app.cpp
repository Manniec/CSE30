#include <server.h>
#include <myLib.h>

using namespace ucm;

int main(int argc, char** argv){

    CrowServer server(argc, argv);

    server.renderHTML("/", "index.html");

    server.route("/intRep", [&](const request& req, response& res){
        if (req.url_params.hasKey("num")){
            std::string numS = req.url_params.get("num");

            int num;

            try{
                num = std::stoi(numS);
            }
            catch (...){
                ucm::json answer;
                answer["valid"] = false;
                res.sendJSON(answer);
                return;
            }

            ucm::json answer = memRep(num);
        
            res.sendJSON(answer);
        } 
        else{
            res.sendError400();
        }
    });

    server.run();
}
