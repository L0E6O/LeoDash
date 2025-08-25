#ifndef API_H
#define API_H
#include <stdint.h>
#include <mutex>

class api
{
public:
    api();
    void apiServerStartup(float* dati, std::mutex* mtx);
};

#endif // API_H
