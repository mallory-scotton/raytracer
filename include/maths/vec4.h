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

#include "maths/vec2.h"
#include "maths/vec3.h"
#include "maths/utils.h"

/*** @brief A 4-dimensional vector class providing basic vector operations. */
struct Vec4
{
    public:
        /*** @brief Default constructor. Initializes vector to (0, 0, 0, 0). */
        Vec4(void);

        /**
         * @brief Initializes vector with given x, y, z values.
         *
         * @param x The x component
         * @param y The y component
         * @param z The z component
         * @param w The w component
         */
        Vec4(float x, float y, float z, float w);

        /**
         * @brief Initializes vector with all components set to the same value.
         *
         * @param a The value to set for all components.
         */
        Vec4(float a);

        /**
         * @brief Initializes vector with Vec2 and sets z, and w to 0.
         *
         * @param v The Vec2 to copy x, and y components from.
         */
        Vec4(const Vec2& v);

        /**
         * @brief Initializes vector with Vec2, given z value and sets w to 0.
         *
         * @param v The Vec2 to copy x, and y components from.
         * @param z The z component
         */
        Vec4(const Vec2& v, float z);

        /**
         * @brief Initializes vector with Vec2 and given z, and w values.
         *
         * @param v The Vec2 to copy x, and y components from.
         * @param z The z component.
         * @param w The w component.
         */
        Vec4(const Vec2& v, float z, float w);

        /**
         * @brief Initializes vector with Vec3 and sets w to 0.
         *
         * @param v The Vec2 to copy x, y, and z components from.
         */
        Vec4(const Vec3& v);

        /**
         * @brief Initializes vector with Vec3 and given w value.
         *
         * @param v The Vec3 to copy x, y, and z components from.
         * @param w The w component.
         */
        Vec4(const Vec3& v, float w);

        /**
         * @brief Copy constructor.
         *
         * @param v The Vec4 to copy.
         */
        Vec4(const Vec4& v);

        /**
         * @brief Multiplies two vectors component-wise.
         *
         * @param v The vector to multiply with.
         *
         * @return The resulting vector.
         */
        Vec4 operator*(const Vec4& v) const;

        /**
         * @brief Divides two vectors component-wise.
         *
         * @param v The vector to divide by.
         *
         * @return The resulting vector.
         */
        Vec4 operator/(const Vec4& v) const;

        /**
         * @brief Adds two vectors component-wise.
         *
         * @param v The vector to add.
         *
         * @return The resulting vector.
         */
        Vec4 operator+(const Vec4& v) const;

        /**
         * @brief Subtracts two vectors component-wise.
         *
         * @param v The vector to subtract.
         *
         * @return The resulting vector.
         */
        Vec4 operator-(const Vec4& v) const;

        /**
         * @brief Multiplies vector by a scalar.
         *
         * @param f The scalar to multiply with.
         *
         * @return The resulting vector.
         */
        Vec4 operator*(float f) const;

        /**
         * @brief Divides vector by a scalar.
         *
         * @param f The scalar to divide by.
         *
         * @return The resulting vector.
         */
        Vec4 operator/(float f) const;

        /**
         * @brief Multiplies this vector by another vector component-wise.
         *
         * @param v The vector to multiply with.
         */
        void operator*=(const Vec4& v);

        /**
         * @brief Divides this vector by another vector component-wise.
         *
         * @param v The vector to divide by.
         */
        void operator/=(const Vec4& v);

        /**
         * @brief Adds another vector to this vector component-wise.
         *
         * @param v The vector to add.
         */
        void operator+=(const Vec4& v);

        /**
         * @brief Subtracts another vector from this vector component-wise.
         *
         * @param v The vector to subtract.
         */
        void operator-=(const Vec4& v);

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
        bool operator==(const Vec4& v) const;

        /**
         * @brief Compares this vector with another vector for inequality.
         *
         * @param v The vector to compare with.
         *
         * @return True if vectors are inequal, false otherwise.
         */
        bool operator!=(const Vec4& v) const;

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
         * @brief Converts to SFML vector.
         *
         * @return The SFML vector.
         */
        operator sf::Vector2f(void) const;

        /**
         * @brief Converts to 3D vector.
         *
         * @return The 3D vector.
         */
        operator Vec3(void) const;

        /**
         * @brief Converts to 2D vector.
         *
         * @return The 2D vector.
         */
        operator Vec2(void) const;

        /**
         * @brief Finds component-wise minimum of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The resulting vector.
         */
        static Vec4 Min(const Vec4& a, const Vec4& b);

        /**
         * @brief Finds component-wise maximum of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The resulting vector.
         */
        static Vec4 Max(const Vec4& a, const Vec4& b);

        /**
         * @brief Raises each component of the vector to a given power.
         *
         * @param a The vector.
         * @param exp The exponent.
         *
         * @return The resulting vector.
         */
        static Vec4 Pow(const Vec4& a, float exp);

        /**
         * @brief Computes the length of the vector.
         *
         * @param a The vector.
         *
         * @return The length of the vector.
         */
        static float Length(const Vec4& a);

        /**
         * @brief Computes the distance between two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The distance between the vectors.
         */
        static float Distance(const Vec4& a, const Vec4& b);

        /**
         * @brief Computes the dot product of two vectors.
         *
         * @param a The first vector.
         * @param b The second vector.
         *
         * @return The dot product.
         */
        static float Dot(const Vec4& a, const Vec4& b);

        /**
         * @brief Clamps the components of the vector between corresponding min and max values.
         *
         * @param a The vector to clamp.
         * @param min The vector of minimum values.
         * @param max The vector of maximum values.
         *
         * @return The resulting clamped vector.
         */
        static Vec4 Clamp(const Vec4& a, const Vec4& min, const Vec4& max);

        /**
         * @brief Normalizes the vector.
         *
         * @param a The vector to normalize.
         *
         * @return The normalized vector.
         */
        static Vec4 Normalize(const Vec4& a);

        /**
         * @brief Moves a vector towards a target vector by a maximum distance delta.
         *
         * @param current The current vector.
         * @param target The target vector.
         * @param maxDistanceDelta The maximum distance to move.
         *
         * @return The resulting vector.
         */
        static Vec4 MoveTowards(const Vec4& current, const Vec4& target, float maxDistanceDelta);

        /**
         * @brief Linearly interpolates between two vectors without clamping the interpolant.
         *
         * @param a The start vector.
         * @param b The end vector.
         * @param t The interpolant, where 0 returns the start vector and 1 returns the end vector.
         *
         * @return The interpolated vector.
         */
        static Vec4 LerpUnclamped(const Vec4& a, const Vec4& b, float t);

        /**
         * @brief Linearly interpolates between two vectors, clamping the interpolant between 0 and 1.
         *
         * @param a The start vector.
         * @param b The end vector.
         * @param t The interpolant, where 0 returns the start vector and 1 returns the end vector. Values outside the range [0, 1] are clamped.
         *
         * @return The interpolated vector.
         */
        static Vec4 Lerp(const Vec4& a, const Vec4& b, float t);

        /**
         * @brief Projects vector v onto the vector normal.
         *
         * @param v The vector to project.
         * @param normal The vector to project onto.
         *
         * @return The projected vector.
         */
        static Vec4 Project(const Vec4& v, const Vec4& normal);

        /*** @brief X, Y, Z, W vector component */
        float x, y, z, w;

        /*** @brief Shorthand for writing Vec4(0, 0, 0, 0) */
        static const Vec4 zero;
        /*** @brief Shorthand for writing Vec4(1, 1, 1, 1) */
        static const Vec4 one;

    inline Vec4::Vec4(void) : x(0.0F), y(0.0F), z(0.0F), w(0.0F) {};
    inline Vec4::Vec4(float x, float y, float z, float w) : x(x), y(y), z(z), w(w) {};
    inline Vec4::Vec4(float a) : x(a), y(a), z(a), w(a) {};
    inline Vec4::Vec4(const Vec2& v) : x(v.x), y(v.y), z(0.0F), w(0.0F) {};
    inline Vec4::Vec4(const Vec2& v, float z) : x(v.x), y(v.y), z(z), w(0.0F) {};
    inline Vec4::Vec4(const Vec2& v, float z, float w) : x(v.x), y(v.y), z(z), w(w) {};
    inline Vec4::Vec4(const Vec3& v) : x(v.x), y(v.y), z(v.z), w(0.0F) {};
    inline Vec4::Vec4(const Vec3& v, float w) : x(v.x), y(v.y), z(v.z), w(w) {};
    inline Vec4::Vec4(const Vec4& v) : x(v.x), y(v.y), z(v.z), w(v.w) {};

    inline Vec4 Vec4::operator*(const Vec4& v) const
    {
        return (Vec4(x * v.x, y * v.y, z * v.z, w * v.w));
    };

    inline Vec4 Vec4::operator/(const Vec4& v) const
    {
        return (Vec4(x / v.x, y / v.y, z / v.z, w / v.w));
    };

    inline Vec4 Vec4::operator+(const Vec4& v) const
    {
        return (Vec4(x + v.x, y + v.y, z + v.z, w + v.w));
    };

    inline Vec4 Vec4::operator-(const Vec4& v) const
    {
        return (Vec4(x - v.x, y - v.y, z - v.z, w - v.w));
    };

    inline Vec4 Vec4::operator*(float f) const
    {
        return (Vec4(x * f, y * f, z * f, w * f));
    };

    inline Vec4 Vec4::operator/(float f) const
    {
        return (Vec4(x / f, y / f, z / f, w / f));
    };

    inline void Vec4::operator*=(const Vec4& v)
    {
        this->x *= v.x; this->y *= v.y; this->z *= v.z; this->w *= v.w;
    };

    inline void Vec4::operator/=(const Vec4& v)
    {
        this->x /= v.x; this->y /= v.y; this->z /= v.z; this->w /= v.w;
    };

    inline void Vec4::operator+=(const Vec4& v)
    {
        this->x += v.x; this->y += v.y; this->z += v.z; this->w += v.w;
    };

    inline void Vec4::operator-=(const Vec4& v)
    {
        this->x -= v.x; this->y -= v.y; this->z -= v.z; this->w -= v.w;
    };

    inline void Vec4::operator*=(float f)
    {
        this->x *= f; this->y *= f; this->z *= f; this->w *= f;
    };

    inline void Vec4::operator/=(float f)
    {
        this->x /= f; this->y /= f; this->z /= f; this->w /= f;
    };

    inline bool Vec4::operator==(const Vec4& v) const
    {
        return (x == v.x && y == v.y && z == v.z && w == v.w);
    };

    inline bool Vec4::operator!=(const Vec4& v) const
    {
        return (!((*this) == v));
    };

    inline float Vec4::operator[](int i) const
    {
        if (i == 0) return (x);
        if (i == 1) return (y);
        if (i == 2) return (z);
        return (w);
    };

    inline float& Vec4::operator[](int i)
    {
        if (i == 0) return (x);
        if (i == 1) return (y);
        if (i == 2) return (z);
        return (w);
    };

    inline operator sf::Vector2f() const
    {
        return (sf::Vector2f(x, y));
    };

    inline operator sf::Vector3f() const
    {
        return (sf::Vector3f(x, y, z));
    };

    inline operator Vec2() const
    {
        return (Vec2(x, y));
    };

    inline operator Vec3() const
    {
        return (Vec3(x, y, z));
    };

    inline Vec4 Vec4::Min(const Vec4& a, const Vec4& b)
    {
        Vec4 out;

        out.x = std::min(a.x, b.x);
        out.y = std::min(a.y, b.y);
        out.z = std::min(a.z, b.z);
        out.w = std::min(a.w, b.w);
        return (out);
    };

    inline Vec4 Vec4::Max(const Vec4& a, const Vec4& b)
    {
        Vec4 out;

        out.x = std::max(a.x, b.x);
        out.y = std::max(a.y, b.y);
        out.z = std::max(a.z, b.z);
        out.w = std::max(a.w, b.w);
        return (out);
    };

    inline Vec4 Vec4::Pow(const Vec4& a, float exp)
    {
        return (Vec4(powf(a.x, exp), powf(a.y, exp), powf(a.z, exp), powf(a.w, exp)));
    };

    inline float Vec4::Length(const Vec4& a)
    {
        return (sqrtf((a.x * a.x) + (a.y * a.y) + (a.z * a.z) + (a.w * a.w)));
    };

    inline float Vec4::Dot(const Vec4& a, const Vec4& b)
    {
        return ((a.x * b.x) + (a.y * b.y) + (a.z * b.z) + (a.w * b.w));
    };

    inline float Vec4::Distance(const Vec4& a, const Vec4& b)
    {
        Vec4 t = a;

        return (Length(t - b));
    };

    inline Vec4 Vec4::Clamp(const Vec4& a, const Vec4& min, const Vec4& max)
    {
        return (Vec4(
            Mathf::Clamp(a.x, min.x, max.x),
            Mathf::Clamp(a.y, min.y, max.y),
            Mathf::Clamp(a.z, min.z, max.z),
            Mathf::Clamp(a.w, min.w, max.w)
        ));
    };

    inline Vec4 Vec4::Normalize(const Vec4& a)
    {
        float l = Length(a);

        return (a / l);
    };

    inline Vec4 Vec4::MoveTowards(const Vec4& current, const Vec4& target, float maxDistanceDelta)
    {
        Vec4 toVector = target - current;
        float sqdist = (toVector.x * toVector.x) + (toVector.y * toVector.y) + (toVector.z * toVector.z) + (toVector.w * toVector.w);

        if (sqdist == 0.0F ||(maxDistanceDelta >= 0.0F && sqdist <= maxDistanceDelta * maxDistanceDelta))
            return (target);

        float dist = sqrtf(sqdist);

        return (Vec4(
            current.x + toVector.x / dist * maxDistanceDelta,
            current.y + toVector.y / dist * maxDistanceDelta,
            current.z + toVector.z / dist * maxDistanceDelta,
            current.w + toVector.w / dist * maxDistanceDelta
        ));
    };

    inline Vec4 Vec4::LerpUnclamped(const Vec4& a, const Vec4& b, float t)
    {
        return (Vec4(
            a.x + (b.x - a.x) * t,
            a.y + (b.y - a.y) * t,
            a.z + (b.z - a.z) * t,
            a.w + (b.w - a.w) * t
        ));
    };

    inline Vec4 Vec4::Lerp(const Vec4& a, const Vec4& b, float t)
    {
        return (LerpUnclamped(a, b, Mathf::Clamp01(t)));
    };

    inline Vec4 Vec4::Project(const Vec4& v, const Vec4& normal)
    {
        float sqrMag = Dot(normal, normal);

        if (sqrMag < Mathf::Epsilon)
            return (zero);

        float dot = Dot(v, normal);

        return (Vec4(
            normal.x * dot / sqrMag,
            normal.y * dot / sqrMag,
            normal.z * dot / sqrMag,
            normal.w * dot / sqrMag
        ));
    };
};

const Vec4 Vec4::zero   = Vec4(0.0F);
const Vec4 Vec4::one    = Vec4(1.0F);

std::ostream& operator<<(std::ostream& os, const Vec4& v)
{
    os << '(' << v.x << ", " << v.y << ", " << v.z << ", " << v.w << ')';
    return (os);
};
