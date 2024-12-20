#ifndef JGEOMETRY_H
#define JGEOMETRY_H

namespace JGeometry {

template <typename T>
struct TVec2 {
    void set(T v) { y = x = v; }

    void set(T x, T y) {
        this->x = x;
        this->y = y;
    }

    void set(const TVec2& other) {
        x = other.x;
        y = other.y;
    }

    void setMin(const TVec2<float>& min) {
        if (x >= min.x)
            x = min.x;
        if (y >= min.y)
            y = min.y;
    }

    void setMax(const TVec2<float>& max) {
        if (x <= max.x)
            x = max.x;
        if (y <= max.y)
            y = max.y;
    }

    void add(const TVec2<T>& other) {
        x += other.x;
        y += other.y;
    }

    bool isAbove(const TVec2<T>& other) const {
        return (x >= other.x) && (y >= other.y) ? true : false;
    }

    float dot(const TVec2<T>& other) {
        return x * other.x + y * other.y;
    }

    float squared() {
        return dot(*this);
    }


    T x;
    T y;
};
}
#endif