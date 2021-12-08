#ifndef IMPRESARIO_UTILS_CONFIG_H
#define IMPRESARIO_UTILS_CONFIG_H

#include <memory>
#include <stdexcept>
#include <yaml-cpp/yaml.h>

namespace impresarioUtils {

class Config {
private:
    static std::unique_ptr<Config> instance;

    YAML::Node configFile;

    Config(std::string &configFilePath);

public:
    static Config &getInstance();

    static void initialize(std::string &configFilePath);

    int getInt(const char *name);

    uint getUint(const char *name);

    std::string getString(const char *name);

    float getFloat(const char *name);

    bool getBool(const char *name);
};

}

#endif //IMPRESARIO_UTILS_CONFIG_H
