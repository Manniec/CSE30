#include <server.h>
#include <myLib.h>

using namespace ucm;

int main(int argc, char** argv){

    CrowServer server(argc, argv);

    server.renderHTML("/", "index.html");

    server.route("/hello", [](const request& req, response& res){
        std::string phrase = sayHello();

        res.sendHTML(phrase);
    });

    server.route("/echo", [](const request& req, response& res){
        if (req.url_params.hasKey("word")){
            std::string word = req.url_params.get("word");

            std::string answer = echoWord(word);
        
            res.sendHTML(answer);
        } 
        else{
            res.sendError400();
        }
    });

    server.route("/superbowl", [](const request& req, response& res){
        json data = getSuperBowlScore();

        res.sendJSON(data);
    });

    server.route("/quad", [](const request& req, response& res){
        if (req.url_params.hasKey("a") && req.url_params.hasKey("b") && req.url_params.hasKey("c")){
            std::string aS = req.url_params.get("a");
            std::string bS = req.url_params.get("b");
            std::string cS = req.url_params.get("c");

            float a = ::atof(aS.c_str());
            float b = ::atof(bS.c_str());
            float c = ::atof(cS.c_str());

            ucm::json answer = quadratic(a, b, c);
        
            res.sendJSON(answer);
        } 
        else{
            res.sendError400();
        }
    });


    server.route("/count_freq", [](const request& req, response& res){
        if (req.url_params.hasKey("char_string")){
            
            std::string str = req.url_params.get("char_string");
        
            ucm::json answer = countMostFreqLetter(str);
        
            res.sendJSON(answer);
        } 
        else{
            res.sendError400();
        }
    });

    server.run();
}
