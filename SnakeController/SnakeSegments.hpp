#pragma once

#include <list>
#include <memory>
#include <stdexcept>
#include <functional>


struct SnakeSegments {
    SnakeSegments() = default;

    struct Segment
    {
        int x;
        int y;
    };

    std::list<Segment> m_segments;

    bool isSegmentAtPosition(int x, int y) const {
        return m_segments.end() !=  std::find_if(m_segments.cbegin(), m_segments.cend(),
        [x, y](auto const& segment){ return segment.x == x and segment.y == y; });
    }

    void removeTailSegment()
    {
    auto tail = m_segments.back();

    Snake::DisplayInd l_evt;
    l_evt.x = tail.x;
    l_evt.y = tail.y;
    l_evt.value = Snake::Cell::Cell_FREE;
    //m_displayPort.send(std::make_unique<EventT<DisplayInd>>(l_evt)); //co z displayPort

    m_segments.pop_back();
    }


};

/*
 za mało czasu..
 plan to wydzielić z klasy Controller do klasy SnakeSegments:
 o strukture Segments? (czy to jest potrzebne? raczej tak, bo Controller ma się zajmować eventami a nie obsługą snejka)
 o isSegmentAtPosition()
 o calculateNewHead()
 o addHeadSegment()
 o removeTailSegmentIfNotScored()
 o removeTailSegment()




to już nie dzisiaj
 do klasy World:
 updateFoodPosition()
 sendClearOldFood()
 sendPlaceNewFood()


 w klasie Controller tworzyć obiekty klas SnakeSegments i World i z nich korzystać
*/