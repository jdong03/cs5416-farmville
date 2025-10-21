#include "FarmLogic.h"
#include "displayobject.hpp"
#include "farmsync.hpp"
#include <atomic>
#include <random>
#include <unistd.h>
#include <thread>
#include <chrono>

inline int clampi(int v, int lo, int hi)
{
    return v < lo ? lo : (v > hi ? hi : v);
}

inline void setPosClamped(DisplayObject *obj, int nx, int ny)
{
    int hw = obj->width / 2;
    int hh = obj->height / 2;
    nx = clampi(nx, hw, 800 - hw);
    ny = clampi(ny, hh, 600 - hh);
    obj->setPos(nx, ny);
    safeUpdateFarm(*obj);
}

void FarmLogic::run()
{
    BakeryStats stats;

    std::atomic<bool> running{true};
    std::thread render_thread([&]()
                              {
    while (running.load()) {
        safeRedisplay(stats);
        std::this_thread::sleep_for(std::chrono::milliseconds(100));
    } });

    render_thread.detach();

    DisplayObject chicken("chicken", 60, 60, 2, 0);
    DisplayObject chicken2("chicken", 60, 60, 2, 1);
    DisplayObject chicken3("chicken", 60, 60, 2, 29);
    DisplayObject nest("nest", 80, 60, 0, 2);
    DisplayObject nest2("nest", 80, 60, 0, 3);
    DisplayObject nest1eggs[3] = {
        DisplayObject("egg", 10, 20, 1, 4),
        DisplayObject("egg", 10, 20, 1, 5),
        DisplayObject("egg", 10, 20, 1, 6)};

    DisplayObject cow("cow", 60, 60, 2, 7);
    DisplayObject cow2("cow", 100, 100, 2, 30);
    DisplayObject truck("truck", 80, 60, 2, 8);
    DisplayObject truck2("truck", 80, 60, 2, 31);
    DisplayObject farmer("farmer", 30, 60, 2, 9);
    DisplayObject child("child", 30, 60, 2, 10);
    DisplayObject child2("child", 30, 60, 2, 32);
    DisplayObject child3("child", 30, 60, 2, 33);
    DisplayObject child4("child", 30, 60, 2, 34);
    DisplayObject child5("child", 30, 60, 2, 35);
    DisplayObject barn1("barn", 100, 100, 0, 11);
    DisplayObject barn2("barn", 100, 100, 0, 12);
    DisplayObject bakery("bakery", 250, 250, 0, 13);
    DisplayObject bakeryeggs[3] = {
        DisplayObject("egg", 10, 20, 1, 14),
        DisplayObject("egg", 10, 20, 1, 15),
        DisplayObject("egg", 10, 20, 1, 16)};
    DisplayObject bakeryflour[3] = {
        DisplayObject("flour", 20, 20, 1, 17),
        DisplayObject("flour", 20, 20, 1, 18),
        DisplayObject("flour", 20, 20, 1, 19)};
    DisplayObject bakerybutter[3] = {
        DisplayObject("butter", 20, 20, 1, 20),
        DisplayObject("butter", 20, 20, 1, 21),
        DisplayObject("butter", 20, 20, 1, 22)};
    DisplayObject bakerysugar[3] = {
        DisplayObject("sugar", 20, 20, 1, 23),
        DisplayObject("sugar", 20, 20, 1, 24),
        DisplayObject("sugar", 20, 20, 1, 25)};

    DisplayObject bakerycake[3] = {
        DisplayObject("cake", 20, 20, 1, 26),
        DisplayObject("cake", 20, 20, 1, 27),
        DisplayObject("cake", 20, 20, 1, 28)};

    chicken.setPos(400, 300);
    chicken2.setPos(300, 300);
    chicken3.setPos(300, 400);
    nest.setPos(100, 500);
    nest2.setPos(700, 500);
    nest1eggs[0].setPos(90, 507);
    nest1eggs[1].setPos(100, 507);
    nest1eggs[2].setPos(110, 507);
    cow.setPos(200, 200);
    cow2.setPos(250, 250);
    truck.setPos(300, 150);
    truck2.setPos(300, 50);
    farmer.setPos(600, 400);
    child.setPos(620, 100);
    child2.setPos(640, 100);
    child3.setPos(660, 100);
    child4.setPos(680, 100);
    child5.setPos(700, 100);
    barn1.setPos(50, 50);
    barn2.setPos(50, 150);
    bakery.setPos(550, 150);
    bakeryeggs[0].setPos(510, 130);
    bakeryeggs[1].setPos(520, 130);
    bakeryeggs[2].setPos(530, 130);

    bakeryflour[0].setPos(500, 110);
    bakeryflour[1].setPos(520, 110);
    bakeryflour[2].setPos(540, 110);

    bakerysugar[0].setPos(500, 90);
    bakerysugar[1].setPos(520, 90);
    bakerysugar[2].setPos(540, 90);

    bakerybutter[0].setPos(500, 70);
    bakerybutter[1].setPos(520, 70);
    bakerybutter[2].setPos(540, 70);

    bakerycake[0].setPos(600, 200);
    bakerycake[1].setPos(620, 200);
    bakerycake[2].setPos(640, 200);

    safeUpdateFarm(chicken);
    safeUpdateFarm(chicken2);
    safeUpdateFarm(chicken3);
    safeUpdateFarm(nest);
    safeUpdateFarm(nest2);
    safeUpdateFarm(nest1eggs[0]);
    safeUpdateFarm(nest1eggs[1]);
    safeUpdateFarm(nest1eggs[2]);
    safeUpdateFarm(cow);
    safeUpdateFarm(cow2);
    safeUpdateFarm(truck);
    safeUpdateFarm(truck2);
    safeUpdateFarm(farmer);
    safeUpdateFarm(child);
    safeUpdateFarm(child2);
    safeUpdateFarm(child3);
    safeUpdateFarm(child4);
    safeUpdateFarm(child5);
    safeUpdateFarm(barn1);
    safeUpdateFarm(barn2);
    safeUpdateFarm(bakery);
    safeUpdateFarm(bakeryeggs[0]);
    safeUpdateFarm(bakeryeggs[1]);
    safeUpdateFarm(bakeryeggs[2]);

    safeUpdateFarm(bakeryflour[0]);
    safeUpdateFarm(bakeryflour[1]);
    safeUpdateFarm(bakeryflour[2]);

    safeUpdateFarm(bakerybutter[0]);
    safeUpdateFarm(bakerybutter[1]);
    safeUpdateFarm(bakerybutter[2]);

    safeUpdateFarm(bakerysugar[0]);
    safeUpdateFarm(bakerysugar[1]);
    safeUpdateFarm(bakerysugar[2]);

    safeUpdateFarm(bakerycake[0]);
    safeUpdateFarm(bakerycake[1]);
    safeUpdateFarm(bakerycake[2]);

    // Movement Helpers
    auto chicken_worker = [](DisplayObject *bird)
    {
        // Thread-local RNG
        thread_local std::mt19937 gen(std::random_device{}());
        std::uniform_int_distribution<int> step(-5, 5);

        int frame = 0;
        int dx = 0, dy = 0;
        while (true)
        {
            frame++;
            if (frame % 5 == 0)
            {
                dx = step(gen);
                dy = step(gen);
            }

            setPosClamped(bird, bird->x + dx, bird->y + dy);
            std::this_thread::sleep_for(std::chrono::milliseconds(100));
        }
    };

    auto oscillate_x = [](DisplayObject *obj, int min_x, int max_x, int step)
    {
        int dir = 1;
        while (true)
        {
            int nx = obj->x + dir * step;
            if (nx < min_x)
            {
                nx = min_x;
                dir = 1;
            }
            if (nx > max_x)
            {
                nx = max_x;
                dir = -1;
            }
            setPosClamped(obj, nx, obj->y);
            std::this_thread::sleep_for(std::chrono::milliseconds(120));
        }
    };

    auto drift_y = [](DisplayObject *obj, int min_y, int max_y, int step)
    {
        int dir = 1;
        while (true)
        {
            int ny = obj->y + dir * step;
            if (ny < min_y)
            {
                ny = min_y;
                dir = 1;
            }
            if (ny > max_y)
            {
                ny = max_y;
                dir = -1;
            }
            setPosClamped(obj, obj->x, ny);
            std::this_thread::sleep_for(std::chrono::milliseconds(140));
        }
    };

    // Spawn Threads
    std::thread t_ch1(chicken_worker, &chicken);
    t_ch1.detach();
    std::thread t_ch2(chicken_worker, &chicken2);
    t_ch2.detach();
    std::thread t_ch3(chicken_worker, &chicken3);
    t_ch3.detach();

    std::thread t_truck(oscillate_x, &truck, 200, 700, 6);
    t_truck.detach();
    std::thread t_truck2(oscillate_x, &truck2, 200, 700, 6);
    t_truck2.detach();

    std::thread t_cow(drift_y, &cow, 120, 360, 3);
    t_cow.detach();
    std::thread t_cow2(drift_y, &cow2, 120, 360, 3);
    t_cow2.detach();

    while (true)
    {
        std::this_thread::sleep_for(std::chrono::seconds(60));
    }
}

void FarmLogic::start()
{
    std::thread([]()
                { FarmLogic::run(); })
        .detach();
}