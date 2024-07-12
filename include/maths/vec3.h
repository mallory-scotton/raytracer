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

#include <SFML/System/Vector3.hpp>
#include "maths/utils.h"
#include "maths/vec4.h"
#include "maths/vec2.h"
#include <iostream>

/*** @brief A 3-dimensional vector class providing basic vector operations. */
struct Vec3
{
    public:
        /*** @brief Default constructor. Initializes vector to (0, 0, 0). */
        Vec3(void);

        /**
         * @brief Initializes vector with given x, y, z values.
         *
         * @param x The x component
         * @param y The y component
         * @param z The z component
         */
        Vec3(float x, float y, float z);

        /**
         * @brief Initializes vector with all components set to the same value.
         *
         * @param a The value to set for all components.
         */
        Vec3(float a);

        /**
         * @brief Initializes vector with Vec2 and sets z to 0.
         *
         * @param v The Vec2 to copy x and y components from.
         */
        Vec3(const Vec2& v);

        /**
         * @brief Initializes vector with Vec2 and given z value.
         *
         * @param v The Vec2 to copy x and y components from.
         * @param z The z component.
         */
        Vec3(const Vec2& v, float z);

        /**
         * @brief Copy constructor.
         *
         * @param v The Vec3 to copy.
         */
        Vec3(const Vec3& v);

        /**
         * @brief Initializes vector with Vec4, discarding w component.
         *
         * @param v The Vec4 to copy x, y, and z components from.
         */
        Vec3(const Vec4& v);

        /**
         * @brief Multiplies two vectors component-wise.
         *
         * @param v The vector to multiply with.
         *
         * @return The resulting vector.
         */
        Vec3 operator*(const Vec3& v) const;

        /**
         * @brief Divides two vectors component-wise.
         *
         * @param v The vector to divide by.
         *
         * @return The resulting vector.
         */
        Vec3 operator/(const Vec3& v) const;

        /**
         * @brief Adds two vectors component-wise.
         *
         * @param v The vector to add.
         *
         * @return The resulting vector.
         */
        Vec3 operator+(const Vec3& v) const;

        /**
         * @brief Subtracts two vectors component-wise.
         *
         * @param v The vector to subtract.
         *
         * @return The resulting vector.
         */
        Vec3 operator-(const Vec3& v) const;

        /**
         * @brief Multiplies vector by a scalar.
         *
         * @param f The scalar to multiply with.
         *
         * @return The resulting vector.
         */
        Vec3 operator*(float f) const;

        /**
         * @brief Divides vector by a scalar.
         *
         * @param f The scalar to divide by.
         *
         * @return The resulting vector.
         */
        Vec3 operator/(float f) const;

        /**
         * @brief Multiplies this vector by another vector component-wise.
         *
         * @param v The vector to multiply with.
         */
        void operator*=(const Vec3& v);

        /**
         * @brief Divides this vector by another vector component-wise.
         *
         * @param v The vector to divide by.
         */
        void operator/=(const Vec3& v);

        /**
         * @brief Adds another vector to this vector component-wise.
         *
         * @param v The vector to add.
         */
        void operator+=(const Vec3& v);

        /**
         * @brief Subtracts another vector from this vector component-wise.
         *
         * @param v The vector to subtract.
         */
        void operator-=(const Vec3& v);

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
        bool operator==(const Vec3& v) const;

        /**
         * @brief Compares this vector with another vector for inequality.
         *
         * @param v The vector to compare with.
         *
         * @return True if vectors are inequal, false otherwise.
         */
        bool operator!=(const Vec3& v) const;

        /**
         * @brief Accesses vector component by index.
         *
         * @param i The index (0 for x, 1 for y, 2 for z).
         *
         * @return The component value.
         */
        float operator[](int i) const;

        /**
         * @brief Accesses vector component by index.
         *
         * @param i The index (0 for x, 1 for y, 2 for z).
         *
         * @return Reference to the component value.
         */
        float& operator[](int i);

        /**
         * @brief Converts to SFML vector.
         *
         * @return The SFML vector.
         */
        operator sf::Vector3f(void) const;

        /**
         * @brief Converts to 2D vector.
         *
         * @return The 2D vector.
         */
        operator Vec2(void) const;

        /**
         * @brief Converts to 4D vector.
         *
         * @return The 4D vector.
         */
        operator Vec4(void) const;

        /**
         * @brief Finds component-wise minimum of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The resulting vector.
         */
        static Vec3 Min(const Vec3& a, const Vec3& b);

        /**
         * @brief Finds component-wise maximum of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The resulting vector.
         */
        static Vec3 Max(const Vec3& a, const Vec3& b);

        /**
         * @brief Computes the cross product of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The resulting vector.
         */
        static Vec3 Cross(const Vec3& a, const Vec3& b);

        /**
         * @brief Raises each component of the vector to a given power.
         *
         * @param a The vector.
         * @param exp The exponent.
         *
         * @return The resulting vector.
         */
        static Vec3 Pow(const Vec3& a, float exp);

        /**
         * @brief Computes the length of the vector.
         *
         * @param a The vector.
         *
         * @return The length of the vector.
         */
        static float Length(const Vec3& a);

        /**
         * @brief Computes the distance between two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The distance between the vectors.
         */
        static float Distance(const Vec3& a, const Vec3& b);

        /**
         * @brief Computes the dot product of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The dot product.
         */
        static float Dot(const Vec3& a, const Vec3& b);

        /**
         * @brief Clamps the components of the vector between corresponding min and max values.
         *
         * @param a The vector to clamp.
         * @param min The vector of minimum values.
         * @param max The vector of maximum values.
         *
         * @return The resulting clamped vector.
         */
        static Vec3 Clamp(const Vec3& a, const Vec3& min, const Vec3& max);

        /**
         * @brief Normalizes the vector.
         *
         * @param a The vector to normalize.
         *
         * @return The normalized vector.
         */
        static Vec3 Normalize(const Vec3& a);

        /**
         * @brief Moves a vector towards a target vector by a maximum distance delta.
         *
         * @param current The current vector.
         * @param target The target vector.
         * @param maxDistanceDelta The maximum distance to move.
         *
         * @return The resulting vector.
         */
        static Vec3 MoveTowards(const Vec3& current, const Vec3& target, float maxDistanceDelta);

        /**
         * @brief Linearly interpolates between two vectors without clamping the interpolant.
         *
         * @param a The start vector.
         * @param b The end vector.
         * @param t The interpolant, where 0 returns the start vector and 1 returns the end vector.
         *
         * @return The interpolated vector.
         */
        static Vec3 LerpUnclamped(const Vec3& a, const Vec3& b, float t);

        /**
         * @brief Linearly interpolates between two vectors, clamping the interpolant between 0 and 1.
         *
         * @param a The start vector.
         * @param b The end vector.
         * @param t The interpolant, where 0 returns the start vector and 1 returns the end vector. Values outside the range [0, 1] are clamped.
         *
         * @return The interpolated vector.
         */
        static Vec3 Lerp(const Vec3& a, const Vec3& b, float t);

        /**
         * @brief Projects vector v onto the vector normal.
         *
         * @param v The vector to project.
         * @param normal The vector to project onto.
         *
         * @return The projected vector.
         */
        static Vec3 Project(const Vec3& v, const Vec3& normal);

        /**
         * @brief Projects vector v onto a plane defined by its normal.
         *
         * @param v The vector to project.
         * @param planeNormal The normal of the plane.
         *
         * @return The projected vector on the plane.
         */
        static Vec3 ProjectOnPlane(const Vec3& v, const Vec3& planeNormal);

        /**
         * @brief Reflects a vector off a surface with a given normal.
         *
         * @param inDirection The incident vector.
         * @param inNormal The normal of the surface.
         *
         * @return The reflected vector.
         */
        static Vec3 Reflect(const Vec3& inDirection, const Vec3& inNormal);

        /**
         * @brief Converts the vector to an SFML vector.
         *
         * @return The SFML vector.
         */
        sf::Vector3f toSFMLVector(void) const;

        /*** @brief X, Y, Z vector component */
        float x, y, z;

        /*** @brief Shorthand for writing Vec3(0, 0, 0) */
        static const Vec3 zero;
        /*** @brief Shorthand for writing Vec3(1, 1, 1) */
        static const Vec3 one;
        /*** @brief Shorthand for writing Vec3(0, 1, 0) */
        static const Vec3 up;
        /*** @brief Shorthand for writing Vec3(0, -1, 0) */
        static const Vec3 down;
        /*** @brief Shorthand for writing Vec3(-1, 0, 0) */
        static const Vec3 left;
        /*** @brief Shorthand for writing Vec3(1, 0, 0) */
        static const Vec3 right;
        /*** @brief Shorthand for writing Vec3(0, 0, 1) */
        static const Vec3 forward;
        /*** @brief Shorthand for writing Vec3(0, 0, -1) */
        static const Vec3 backward;

    inline Vec3::Vec3(void) : x(0.0F), y(0.0F), z(0.0F) {};
    inline Vec3::Vec3(float x, float y, float z) : x(x), y(y), z(z) {};
    inline Vec3::Vec3(float a) : x(a), y(a), z(a) {};
    inline Vec3::Vec3(const Vec2& v) : x(v.x), y(v.y), z(0.0F) {};
    inline Vec3::Vec3(const Vec2& v, float z) : x(v.x), y(v.y), z(z) {};
    inline Vec3::Vec3(const Vec3& v) : x(v.x), y(v.y), z(v.z) {};
    inline Vec3::Vec3(const Vec4& v) : x(v.x), y(v.y), z(v.z) {};

    inline Vec3 Vec3::operator*(const Vec3& v) const
    {
        return (Vec3(x * v.x, y * v.y, z * v.z));
    };

    inline Vec3 Vec3::operator/(const Vec3& v) const
    {
        return (Vec3(x / v.x, y / v.y, z / v.z));
    };

    inline Vec3 Vec3::operator+(const Vec3& v) const
    {
        return (Vec3(x + v.x, y + v.y, z + v.z));
    };

    inline Vec3 Vec3::operator-(const Vec3& v) const
    {
        return (Vec3(x - v.x, y - v.y, z - v.z));
    };

    inline Vec3 Vec3::operator*(float f) const
    {
        return (Vec3(x * f, y * f, z * f));
    };

    inline Vec3 Vec3::operator/(float f) const
    {
        return (Vec3(x / f, y / f, z / f));
    };

    inline void Vec3::operator*=(const Vec3& v)
    {
        this->x *= v.x; this->y *= v.y; this->z *= v.z;
    };

    inline void Vec3::operator/=(const Vec3& v)
    {
        this->x /= v.x; this->y /= v.y; this->z /= v.z;
    };

    inline void Vec3::operator+=(const Vec3& v)
    {
        this->x += v.x; this->y += v.y; this->z += v.z;
    };

    inline void Vec3::operator-=(const Vec3& v)
    {
        this->x -= v.x; this->y -= v.y; this->z -= v.z;
    };

    inline void Vec3::operator*=(float f)
    {
        this->x *= f; this->y *= f; this->z *= f;
    };

    inline void Vec3::operator/=(float f)
    {
        this->x /= f; this->y /= f; this->z /= f;
    };

    inline bool Vec3::operator==(const Vec3& v) const
    {
        return (x == v.x && y == v.y && z == v.z);
    };

    inline bool Vec3::operator!=(const Vec3& v) const
    {
        return (!((*this) == v));
    };

    inline float Vec3::operator[](int i) const
    {
        if (i == 0) return (x);
        if (i == 1) return (y);
        return (z);
    };

    inline float& Vec3::operator[](int i)
    {
        if (i == 0) return (x);
        if (i == 1) return (y);
        return (z);
    };

    inline operator sf::Vector3f(void) const
    {
        return (sf::Vector3f(x, y, z));
    };

    inline operator Vec2(void) const
    {
        return (Vec2(x, y));
    };

    inline operator Vec4(void) const
    {
        return (Vec4(x, y, z, 0.0F));
    };

    inline Vec3 Vec3::Min(const Vec3& a, const Vec3& b)
    {
        Vec3 out;

        out.x = std::min(a.x, b.x);
        out.y = std::min(a.y, b.y);
        out.z = std::min(a.z, b.z);
        return (out);
    };

    inline Vec3 Vec3::Max(const Vec3& a, const Vec3& b)
    {
        Vec3 out;

        out.x = std::max(a.x, b.x);
        out.y = std::max(a.y, b.y);
        out.z = std::max(a.z, b.z);
        return (out);
    };

    inline Vec3 Vec3::Cross(const Vec3& a, const Vec3& b)
    {
        return (Vec3(
            (a.y * b.z) - (a.z * b.y),
            (a.z * b.x) - (a.x * b.z),
            (a.x * b.y) - (a.y * b.x)
        ));
    };

    inline Vec3 Vec3::Pow(const Vec3& a, float exp)
    {
        return (Vec3(powf(a.x, exp), powf(a.y, exp), powf(a.z, exp)));
    };

    inline float Vec3::Length(const Vec3& a)
    {
        return (sqrtf((a.x * a.x) + (a.y * a.y) + (a.z * a.z)));
    };

    inline float Vec3::Dot(const Vec3& a, const Vec3& b)
    {
        return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z));
    };

    inline float Vec3::Distance(const Vec3& a, const Vec3& b)
    {
        Vec3 t = a;

        return (Length(t - b));
    };

    inline Vec3 Vec3::Clamp(const Vec3& a, const Vec3& min, const Vec3& max)
    {
        return (Vec3(
            Mathf::Clamp(a.x, min.x, max.x),
            Mathf::Clamp(a.y, min.y, max.y),
            Mathf::Clamp(a.z, min.z, max.z)
        ));
    };

    inline Vec3 Vec3::Normalize(const Vec3& a)
    {
        float l = Length(a);

        return (a / l);
    };

    inline Vec3 Vec3::MoveTowards(const Vec3& current, const Vec3& target, float maxDistanceDelta)
    {
        Vec3 toVector = target - current;
        float sqdist = (toVector.x * toVector.x) + (toVector.y * toVector.y) + (toVector.z * toVector.z);

        if (sqdist == 0.0F ||(maxDistanceDelta >= 0.0F && sqdist <= maxDistanceDelta * maxDistanceDelta))
            return (target);

        float dist = sqrtf(sqdist);

        return (Vec3(
            current.x + toVector.x / dist * maxDistanceDelta,
            current.y + toVector.y / dist * maxDistanceDelta,
            current.z + toVector.z / dist * maxDistanceDelta
        ));
    };

    inline Vec3 Vec3::LerpUnclamped(const Vec3& a, const Vec3& b, float t)
    {
        return (Vec3(
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t
        ));
    };

    inline Vec3 Vec3::Lerp(const Vec3& a, const Vec3& b, float t)
    {
        return (LerpUnclamped(a, b, Mathf::Clamp01(t)));
    };

    inline Vec3 Vec3::Project(const Vec3& v, const Vec3& normal)
    {
        float sqrMag = Dot(normal, normal);

        if (sqrMag < Mathf::Epsilon)
            return (zero);

        float dot = Dot(v, normal);

        return (Vec3(
            normal.x * dot / sqrMag,
            normal.y * dot / sqrMag,
            normal.z * dot / sqrMag
        ));
    };

    inline Vec3 Vec3::ProjectOnPlane(const Vec3& v, const Vec3& planeNormal)
    {
        float sqrMag = Dot(planeNormal, planeNormal);

        if (sqrMag < Mathf::Epsilon)
            return (v);

        float dot = Dot(v, planeNormal);

        return (Vec3(
            v.x - planeNormal.x * dot / sqrMag,
            v.y - planeNormal.y * dot / sqrMag,
            v.z - planeNormal.z * dot / sqrMag
        ));
    };

    inline Vec3 Vec3::Reflect(const Vec3& inDirection, const Vec3& inNormal)
    {
        float factor = -2.0F * Dot(inNormal, inDirection);

        return (Vec3(
            factor * inNormal.x + inDirection.x,
            factor * inNormal.y + inDirection.y,
            factor * inNormal.z + inDirection.z
        ));
    };

    inline sf::Vector3f Vec3::toSFMLVector(void)
    {
        return (sf::Vector3f(x, y, z));
    };
};

const Vec3 Vec3::zero       = Vec3( 0.0F,  0.0F,  0.0F);
const Vec3 Vec3::one        = Vec3( 1.0F,  1.0F,  1.0F);
const Vec3 Vec3::up         = Vec3( 0.0F,  1.0F,  0.0F);
const Vec3 Vec3::down       = Vec3( 0.0F, -1.0F,  0.0F);
const Vec3 Vec3::left       = Vec3(-1.0F,  0.0F,  0.0F);
const Vec3 Vec3::right      = Vec3( 1.0F,  0.0F,  0.0F);
const Vec3 Vec3::forward    = Vec3( 0.0F,  0.0F,  1.0F);
const Vec3 Vec3::backward   = Vec3( 0.0F,  0.0F, -1.0F);

std::ostream& operator<<(std::ostream& os, const Vec3& v)
{
    os << '(' << v.x << ", " << v.y << ", " << v.z << ')';
    return (os);
};
