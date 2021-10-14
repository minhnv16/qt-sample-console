#include <stdio.h>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <iostream>
using namespace std;

int nData = 1;
std::condition_variable cv;
std::mutex g_mutex;



void worker_thread()
{
    printf("thread is processing data\n");
    while(nData!=0){
        std::unique_lock<std::mutex> lck(g_mutex);
        printf("thread waiting...\n");

        cv.wait(lck);
        printf("thread event nData = %d\n", nData);


    }
}

void worker_thread2()
{
    printf("thread2 is processing data\n");
    while(nData!=0){
        std::unique_lock<std::mutex> lck(g_mutex);
        printf("thread2 waiting...\n");

        cv.wait(lck);
        printf("thread2 event nData = %d\n", nData);

    }
}


int main(){
    printf("Main hehe\n");
    std::thread worker(worker_thread);
    std::thread worker2(worker_thread2);

    while(nData!=0) {
        fflush(stdin);
        printf("main input nData=");
        std::cin>>nData;
        printf("main print nData=%d\n", nData);
        cv.notify_one();

    }
    printf("Exit main loop \n");
    worker.join();
    worker2.join();
    return 0;
}

