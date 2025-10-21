#pragma once
#include <mutex>
#include "displayobject.hpp"

inline std::mutex g_farm_io_mtx;

inline void safeUpdateFarm(DisplayObject &obj)
{
  std::lock_guard<std::mutex> lk(g_farm_io_mtx);
  obj.updateFarm();
}

inline void safeErase(DisplayObject &obj)
{
  std::lock_guard<std::mutex> lk(g_farm_io_mtx);
  obj.erase();
}

inline void safeRedisplay(BakeryStats &stats)
{
  std::lock_guard<std::mutex> lk(g_farm_io_mtx);
  DisplayObject::redisplay(stats);
}
