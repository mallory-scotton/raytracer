/*
 * MIT License
 *
 * Copyright(c) 2024 Mallory SCOTTON
 *
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following coditions:
 *
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software?
 *
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/

#pragma once

#include <SFML/System/Vector2.hpp>
#include "maths/vec3.h"
#include "maths/vec4.h"

/*** @brief A 2-dimensional vector class providing basic vector operations. */
struct Vec2
{
    public:
        /*** @brief Default constructor. Initializes vector to (0, 0). */
        Vec2(void);

        /**
         * @brief Initializes vector with given x, y values.
         *
         * @param x The x component
         * @param y The y component
         */
        Vec2(float x, float y);

        /**
         * @brief Initializes vector with all components set to the same value.
         *
         * @param a The value to set for all components.
         */
        Vec2(float a);

        /**
         * @brief Copy constructor.
         *
         * @param v The Vec2 to copy.
         */
        Vec2(const Vec2& v);

        /**
         * @brief Initializes vector with Vec3, discarding z component.
         *
         * @param v The Vec3 to copy x, and y components from.
         */
        Vec2(const Vec3& v);

        /**
         * @brief Initializes vector with Vec4, discarding z and w components.
         *
         * @param v The Vec4 to copy x, and y components from.
         */
        Vec2(const Vec4& v);

        /**
         * @brief Multiplies two vectors component-wise.
         *
         * @param v The vector to multiply with.
         *
         * @return The resulting vector.
         */
        Vec2 operator*(const Vec2& v) const;

        /**
         * @brief Divides two vectors component-wise.
         *
         * @param v The vector to divide by.
         *
         * @return The resulting vector.
         */
        Vec2 operator/(const Vec2& v) const;

        /**
         * @brief Adds two vectors component-wise.
         *
         * @param v The vector to add.
         *
         * @return The resulting vector.
         */
        Vec2 operator+(const Vec2& v) const;

        /**
         * @brief Subtracts two vectors component-wise.
         *
         * @param v The vector to subtract.
         *
         * @return The resulting vector.
         */
        Vec2 operator-(const Vec2& v) const;

        /**
         * @brief Multiplies vector by a scalar.
         *
         * @param f The scalar to multiply with.
         *
         * @return The resulting vector.
         */
        Vec2 operator*(float f) const;

        /**
         * @brief Divides vector by a scalar.
         *
         * @param f The scalar to divide by.
         *
         * @return The resulting vector.
         */
        Vec2 operator/(float f) const;

        /**
         * @brief Multiplies this vector by another vector component-wise.
         *
         * @param v The vector to multiply with.
         */
        void operator*=(const Vec2& v);

        /**
         * @brief Divides this vector by another vector component-wise.
         *
         * @param v The vector to divide by.
         */
        void operator/=(const Vec2& v);

        /**
         * @brief Adds another vector to this vector component-wise.
         *
         * @param v The vector to add.
         */
        void operator+=(const Vec2& v);

        /**
         * @brief Subtracts another vector from this vector component-wise.
         *
         * @param v The vector to subtract.
         */
        void operator-=(const Vec2& v);

        /**
         * @brief Multiplies this vector by a scalar.
         *
         * @param f The scalar to multiply with.
         */
        void operator*=(float f);

        /**
         * @brief Divides this vector by a scalar.
         *
         * @param f The scalar to divide by.
         */
        void operator/=(float f);

        /**
         * @brief Compares this vector with another vector for equality.
         *
         * @param v The vector to compare with.
         *
         * @return True if vectors are equal, false otherwise.
         */
        bool operator==(const Vec2& v) const;

        /**
         * @brief Compares this vector with another vector for inequality.
         *
         * @param v The vector to compare with.
         *
         * @return True if vectors are inequal, false otherwise.
         */
        bool operator!=(const Vec2& v) const;

        /**
         * @brief Accesses vector component by index.
         *
         * @param i The index (0 for x, 1 for y).
         *
         * @return The component value.
         */
        float operator[](int i) const;

        /**
         * @brief Accesses vector component by index.
         *
         * @param i The index (0 for x, 1 for y).
         *
         * @return Reference to the component value.
         */
        float& operator[](int i);

        /**
         * @brief Converts to SFML vector.
         *
         * @return The SFML vector.
         */
        operator sf::Vector2f(void) const;

        /**
         * @brief Finds component-wise minimum of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The resulting vector.
         */
        static Vec2 Min(const Vec2& a, const Vec2& b);

        /**
         * @brief Finds component-wise maximum of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The resulting vector.
         */
        static Vec2 Max(const Vec2& a, const Vec2& b);

        /**
         * @brief Raises each component of the vector to a given power.
         *
         * @param a The vector.
         * @param exp The exponent.
         *
         * @return The resulting vector.
         */
        static Vec2 Pow(const Vec2& a, float exp);

        /**
         * @brief Computes the length of the vector.
         *
         * @param a The vector.
         *
         * @return The length of the vector.
         */
        static float Length(const Vec2& a);

        /**
         * @brief Computes the distance between two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The distance between the vectors.
         */
        static float Distance(const Vec2& a, const Vec2& b);

        /**
         * @brief Computes the dot product of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The dot product.
         */
        static float Dot(const Vec2& a, const Vec2& b);

        /**
         * @brief Clamps the components of the vector between corresponding min and max values.
         *
         * @param a The vector to clamp.
         * @param min The vector of minimum values.
         * @param max The vector of maximum values.
         *
         * @return The resulting clamped vector.
         */
        static Vec2 Clamp(const Vec2& a, const Vec2& min, const Vec2& max);

        /**
         * @brief Normalizes the vector.
         *
         * @param a The vector to normalize.
         *
         * @return The normalized vector.
         */
        static Vec2 Normalize(const Vec2& a);

        /**
         * @brief Moves a vector towards a target vector by a maximum distance delta.
         *
         * @param current The current vector.
         * @param target The target vector.
         * @param maxDistanceDelta The maximum distance to move.
         *
         * @return The resulting vector.
         */
        static Vec2 MoveTowards(const Vec2& current, const Vec2& target, float maxDistanceDelta);

        /**
         * @brief Linearly interpolates between two vectors without clamping the interpolant.
         *
         * @param a The start vector.
         * @param b The end vector.
         * @param t The interpolant, where 0 returns the start vector and 1 returns the end vector.
         *
         * @return The interpolated vector.
         */
        static Vec2 LerpUnclamped(const Vec2& a, const Vec2& b, float t);

        /**
         * @brief Linearly interpolates between two vectors, clamping the interpolant between 0 and 1.
         *
         * @param a The start vector.
         * @param b The end vector.
         * @param t The interpolant, where 0 returns the start vector and 1 returns the end vector. Values outside the range [0, 1] are clamped.
         *
         * @return The interpolated vector.
         */
        static Vec2 Lerp(const Vec2& a, const Vec2& b, float t);

        /**
         * @brief Reflects a vector off a surface with a given normal.
         *
         * @param inDirection The incident vector.
         * @param inNormal The normal of the surface.
         *
         * @return The reflected vector.
         */
        static Vec2 Reflect(const Vec2& inDirection, const Vec2& inNormal);

        /**
         * @brief Calculates a perpendicular vector to the input vector.
         *
         * @param v The input vector.
         *
         * @return A perpendicular vector to v.
         */
        static Vec2 Perpendicular(const Vec2& v);

        /**
         * @brief Converts the vector to an SFML vector.
         *
         * @return The SFML vector.
         */
        sf::Vector2f toSFMLVector(void) const;

        float x, y;

        /*** @brief Shorthand for writing Vec2(0, 0) */
        static const Vec2 zero;
        /*** @brief Shorthand for writing Vec2(1, 1) */
        static const Vec2 one;
        /*** @brief Shorthand for writing Vec2(0, 1) */
        static const Vec2 up;
        /*** @brief Shorthand for writing Vec2(0, -1) */
        static const Vec2 down;
        /*** @brief Shorthand for writing Vec2(-1, 0) */
        static const Vec2 left;
        /*** @brief Shorthand for writing Vec2(1, 0) */
        static const Vec2 right;

    inline Vec2::Vec2(void) : x(0.0F), y(0.0F) {};
    inline Vec2::Vec2(float x, float y) : x(x), y(y) {};
    inline Vec2::Vec2(float a) : x(a), y(a) {};
    inline Vec2::Vec2(const Vec2& v) : x(v.x), y(v.y) {};
    inline Vec2::Vec2(const Vec3& v) : x(v.x), y(v.y) {};
    inline Vec2::Vec2(const Vec4& v) : x(v.x), y(v.y) {};

    inline Vec2 Vec2::operator*(const Vec2& v) const
    {
        return (Vec2(x * v.x, y * v.y));
    };

    inline Vec2 Vec2::operator/(const Vec2& v) const
    {
        return (Vec2(x / v.x, y / v.y));
    };

    inline Vec2 Vec2::operator+(const Vec2& v) const
    {
        return (Vec2(x + v.x, y + v.y));
    };

    inline Vec2 Vec2::operator-(const Vec2& v) const
    {
        return (Vec2(x - v.x, y - v.y));
    };

    inline Vec2 Vec2::operator*(float f) const
    {
        return (Vec2(x * f, y * f));
    };

    inline Vec2 Vec2::operator/(float f) const
    {
        return (Vec2(x / f, y / f));
    };

    inline void Vec2::operator*=(const Vec2& v)
    {
        this->x *= v.x; this->y *= v.y;
    };

    inline void Vec2::operator/=(const Vec2& v)
    {
        this->x /= v.x; this->y /= v.y;
    };

    inline void Vec2::operator+=(const Vec2& v)
    {
        this->x += v.x; this->y += v.y;
    };

    inline void Vec2::operator-=(const Vec2& v)
    {
        this->x -= v.x; this->y -= v.y;
    };

    inline void Vec2::operator*=(float f)
    {
        this->x *= f; this->y *= f;
    };

    inline void Vec2::operator/=(float f)
    {
        this->x /= f; this->y /= f;
    };

    inline bool Vec2::operator==(const Vec2& v) const
    {
        return (x == v.x && y == v.y);
    };

    inline bool Vec2::operator!=(const Vec2& v) const
    {
        return (!((*this) == v));
    };

    inline float Vec2::operator[](int i) const
    {
        return ((i == 0) ? x : y);
    };

    inline float& Vec2::operator[](int i)
    {
        return ((i == 0) ? x : y);
    };

    inline operator sf::Vector2f() const
    {
        return (sf::Vector2f(x, y));
    };

    inline Vec2 Vec2::Min(const Vec2& a, const Vec2& b)
    {
        Vec2 out;

        out.x = std::min(a.x, b.x);
        out.y = std::min(a.y, b.y);
        return (out);
    };

    inline Vec2 Vec2::Max(const Vec2& a, const Vec2& b)
    {
        Vec2 out;

        out.x = std::max(a.x, b.x);
        out.y = std::max(a.y, b.y);
        return (out);
    };

    inline Vec2 Vec2::Pow(const Vec2& a, float exp)
    {
        return (Vec2(powf(a.x, exp), powf(a.y, exp)));
    };

    inline float Vec2::Length(const Vec2& a)
    {
        return (sqrtf((a.x * a.x) + (a.y * a.y)));
    };

    inline float Vec2::Distance(const Vec2& a, const Vec2& b)
    {
        Vec2 t = a;

        return (Length(t - b));
    };

    inline float Vec2::Dot(const Vec2& a, const Vec2& b)
    {
        return ((a.x * b.x) + (a.y * b.y));
    };

    inline Vec2 Vec2::Clamp(const Vec2& a, const Vec2& min, const Vec2& max)
    {
        return (Vec2(
            Math::Clamp(a.x, min.x, max.x),
            Math::Clamp(a.y, min.y, max.y)
        ));
    };

    inline Vec2 Vec2::Normalize(const Vec2& a)
    {
        float l = Length(a);

        return (a / l);
    };

    inline Vec2 Vec2::MoveTowards(const Vec2& current, const Vec2& target, float maxDistanceDelta)
    {
        Vec2 toVector = target - current;
        float sqdist = (toVector.x * toVector.x) + (toVector.y * toVector.y);

        if (sqdist == 0.0F ||(maxDistanceDelta >= 0.0F && sqdist <= maxDistanceDelta * maxDistanceDelta))
            return (target);

        float dist = sqrtf(sqdist);

        return (Vec2(
            current.x + toVector.x / dist * maxDistanceDelta,
            current.y + toVector.y / dist * maxDistanceDelta
        ));
    };

    inline Vec2 Vec2::LerpUnclamped(const Vec2& a, const Vec2& b, float t)
    {
        return (Vec2(
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t
        ));
    };

    inline Vec2 Vec2::Lerp(const Vec2& a, const Vec2& b, float t)
    {
        return (LerpUnclamped(a, b, Math::Clamp01(t)));
    };

    inline Vec2 Vec2::Reflect(const Vec2& inDirection, const Vec2& inNormal)
    {
        float factor = -2.0F * Dot(inNormal, inDirection);

        return (Vec2(
            factor * inNormal.x + inDirection.x,
            factor * inNormal.y + inDirection.y
        ));
    };

    inline Vec2 Vec2::Perpendicular(const Vec2& v)
    {
        return (Vec2(-v.y, v.x));
    };
};

const Vec2 Vec2::zero       = Vec2( 0.0F,  0.0F);
const Vec2 Vec2::one        = Vec2( 1.0F,  1.0F);
const Vec2 Vec2::up         = Vec2( 0.0F,  1.0F);
const Vec2 Vec2::down       = Vec2( 0.0F, -1.0F);
const Vec2 Vec2::left       = Vec2(-1.0F,  0.0F);
const Vec2 Vec2::right      = Vec2( 1.0F,  0.0F);

std::ostream& operator<<(std::ostream& os, const Vec2& v)
{
    os << '(' << v.x << ", " << v.y << ')';
    return (os);
};
