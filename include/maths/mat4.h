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

#include "maths/vec3.h"

struct Mat4
{
    public:
        /*** @brief Default constructor initializes a 4x4 matrix to identity. */
        Mat4(void);

        /**
         * @brief Constructor initializing the matrix with specified column vectors.
         *
         * @param c0 Column 0 vector.
         * @param c1 Column 1 vector.
         * @param c2 Column 2 vector.
         * @param c3 Column 3 vector.
         */
        Mat4(const Vec4& c0, const Vec4& c1, const Vec4& c2, const Vec4& c3);

        /**
         * @brief Copy constructor to create a matrix as a copy of another matrix.
         *
         * @param m The matrix to copy.
         */
        Mat4(const Mat4& m);

        /**
         * @brief Accessor to retrieve a reference to a specific row of the matrix.
         *
         * @param i The index of the row.
         *
         * @return Reference to the array representing the row.
         */
        float(&operator [](int i))[4] { return data[i]; };

        /**
         * @brief Multiplies this matrix by another matrix.
         *
         * @param b The matrix to multiply with.
         *
         * @return The resulting matrix after multiplication.
         */
        Mat4 operator*(const Mat4& b) const;

        /**
         * @brief Checks equality between this matrix and another matrix.
         *
         * @param b The matrix to compare with.
         *
         * @return True if matrices are equal, false otherwise.
         */
        bool operator==(const Mat4& b) const;

        /**
         * @brief Checks inequality between this matrix and another matrix.
         *
         * @param b The matrix to compare with.
         *
         * @return True if matrices are not equal, false otherwise.
         */
        bool operator!=(const Mat4& b) const;

        /**
         * @brief Creates a translation matrix from a given translation vector.
         *
         * @param a The translation vector.
         *
         * @return The translation matrix.
         */
        static Mat4 Translate(const Vec3& a);

        /**
         * @brief Creates a scaling matrix from a given scaling vector.
         *
         * @param a The scaling vector.
         *
         * @return The scaling matrix.
         */
        static Mat4 Scale(const Vec3& a);

        /**
         * @brief Converts a quaternion to a rotation matrix.
         *
         * @param x Quaternion x component.
         * @param y Quaternion y component.
         * @param z Quaternion z component.
         * @param w Quaternion w component.
         *
         * @return The rotation matrix representing the quaternion.
         */
        static Mat4 QuatToMatrix(float x, float y, float z, float w);

        /**
         * @brief Retrieves a column vector from the matrix.
         *
         * @param index The index of the column.
         *
         * @return The column vector.
         */
        Vec4 GetColumn(int index) const;

        /**
         * @brief Sets a column vector in the matrix.
         *
         * @param index The index of the column to set.
         * @param c The column vector to set.
         */
        void SetColumn(int index, const Vec4& c);

        /**
         * @brief Retrieves a row vector from the matrix.
         *
         * @param index The index of the row.
         *
         * @return The row vector.
         */
        Vec4 GetRow(int index) const;

        /**
         * @brief Sets a row vector in the matrix.
         *
         * @param index The index of the row to set.
         * @param r The row vector to set.
         */
        void SetRow(int index, const Vec4& r);

        /**
         * @brief Retrieves the translation component from the matrix as a 3D vector.
         *
         * @return The translation vector.
         */
        Vec3 GetPosition(void) const;

        /**
         * @brief Transforms a point by this matrix, considering it as a 4x4 transformation.
         *
         * @param pts The point to transform.
         *
         * @return The transformed point.
         */
        static Vec3 MultiplyPoint(const Vec3& pts);

        /**
         * @brief Transforms a point by this matrix, considering it as a 3x4 transformation (ignoring perspective).
         *
         * @param pts The point to transform.
         *
         * @return The transformed point.
         */
        static Vec3 MultiplyPoint3x4(const Vec3& pts);

        /**
         * @brief Transforms a vector by this matrix (ignoring translation).
         *
         * @param v The vector to transform.
         *
         * return The transformed vector.
         */
        static Vec3 MultiplyVector(const Vec3& v);

        /** Data storage for the matrix, organized as a 4x4 array of floats. */
        float data[4][4];

        /*** @brief Shorthand for writing a 0 matrix */
        static const Mat4 zero;
        /*** @brief Shorthand for writing an identity matrix */
        static const Mat4 identity;

    inline Mat4::Mat4(void)
    {
        data[0][0] = 1.0F; data[0][1] = 0.0F; data[0][2] = 0.0F; data[0][3] = 0.0F;
        data[1][0] = 0.0F; data[1][1] = 1.0F; data[1][2] = 0.0F; data[1][3] = 0.0F;
        data[2][0] = 0.0F; data[2][1] = 0.0F; data[2][2] = 1.0F; data[2][3] = 0.0F;
        data[3][0] = 0.0F; data[3][1] = 0.0F; data[3][2] = 0.0F; data[3][3] = 1.0F;
    };

    inline Mat4::Mat4(const Vec4& c0, const Vec4& c1, const Vec4& c2, const Vec4& c3)
    {
        data[0][0] = c0.x; data[0][1] = c0.y; data[0][2] = c0.z; data[0][3] = c0.w;
        data[1][0] = c1.x; data[1][1] = c0.y; data[1][2] = c1.z; data[1][3] = c1.w;
        data[2][0] = c2.x; data[2][1] = c0.y; data[2][2] = c2.z; data[2][3] = c2.w;
        data[3][0] = c3.x; data[3][1] = c0.y; data[3][2] = c3.z; data[3][3] = c3.w;
    };

    inline Mat4::Mat4(const Mat4& m)
    {
        data[0][0] = m.data[0][0]; data[0][1] = m.data[0][1]; data[0][2] = m.data[0][2]; data[0][3] = m.data[0][3];
        data[1][0] = m.data[1][0]; data[1][1] = m.data[1][1]; data[1][2] = m.data[1][2]; data[1][3] = m.data[1][3];
        data[2][0] = m.data[2][0]; data[2][1] = m.data[2][1]; data[2][2] = m.data[2][2]; data[2][3] = m.data[2][3];
        data[3][0] = m.data[3][0]; data[3][1] = m.data[3][1]; data[3][2] = m.data[3][2]; data[3][3] = m.data[3][3];
    };

    inline Mat4 Mat4::operator*(const Mat4& b) const
    {
        Mat4 out;

        out[0][0] = (data[0][0] * b.data[0][0]) + (data[0][1] * b.data[1][0]) +(data[0][2] * b.data[2][0]) + (data[0][3] * b.data[3][0]);
        out[0][1] = (data[0][0] * b.data[0][1]) + (data[0][1] * b.data[1][1]) +(data[0][2] * b.data[2][1]) + (data[0][3] * b.data[3][1]);
        out[0][2] = (data[0][0] * b.data[0][2]) + (data[0][1] * b.data[1][2]) +(data[0][2] * b.data[2][2]) + (data[0][3] * b.data[3][2]);
        out[0][3] = (data[0][0] * b.data[0][3]) + (data[0][1] * b.data[1][3]) +(data[0][2] * b.data[2][3]) + (data[0][3] * b.data[3][3]);

        out[1][0] = (data[1][0] * b.data[0][0]) + (data[1][1] * b.data[1][0]) +(data[1][2] * b.data[2][0]) + (data[1][3] * b.data[3][0]);
        out[1][1] = (data[1][0] * b.data[0][1]) + (data[1][1] * b.data[1][1]) +(data[1][2] * b.data[2][1]) + (data[1][3] * b.data[3][1]);
        out[1][2] = (data[1][0] * b.data[0][2]) + (data[1][1] * b.data[1][2]) +(data[1][2] * b.data[2][2]) + (data[1][3] * b.data[3][2]);
        out[1][3] = (data[1][0] * b.data[0][3]) + (data[1][1] * b.data[1][3]) +(data[1][2] * b.data[2][3]) + (data[1][3] * b.data[3][3]);

        out[2][0] = (data[2][0] * b.data[0][0]) + (data[2][1] * b.data[1][0]) +(data[2][2] * b.data[2][0]) + (data[2][3] * b.data[3][0]);
        out[2][1] = (data[2][0] * b.data[0][1]) + (data[2][1] * b.data[1][1]) +(data[2][2] * b.data[2][1]) + (data[2][3] * b.data[3][1]);
        out[2][2] = (data[2][0] * b.data[0][2]) + (data[2][1] * b.data[1][2]) +(data[2][2] * b.data[2][2]) + (data[2][3] * b.data[3][2]);
        out[2][3] = (data[2][0] * b.data[0][3]) + (data[2][1] * b.data[1][3]) +(data[2][2] * b.data[2][3]) + (data[2][3] * b.data[3][3]);

        out[3][0] = (data[3][0] * b.data[0][0]) + (data[3][1] * b.data[1][0]) +(data[3][2] * b.data[2][0]) + (data[3][3] * b.data[3][0]);
        out[3][1] = (data[3][0] * b.data[0][1]) + (data[3][1] * b.data[1][1]) +(data[3][2] * b.data[2][1]) + (data[3][3] * b.data[3][1]);
        out[3][2] = (data[3][0] * b.data[0][2]) + (data[3][1] * b.data[1][2]) +(data[3][2] * b.data[2][2]) + (data[3][3] * b.data[3][2]);
        out[3][3] = (data[3][0] * b.data[0][3]) + (data[3][1] * b.data[1][3]) +(data[3][2] * b.data[2][3]) + (data[3][3] * b.data[3][3]);

        return (out);
    };

    inline bool Mat4::operator==(const Mat4& b) const
    {
        return (
            GetColumn(0) == b.GetColumn(0) &&
            GetColumn(1) == b.GetColumn(1) &&
            GetColumn(2) == b.GetColumn(2) &&
            GetColumn(3) == b.GetColumn(3)
        );
    };

    inline bool Mat4::operator!=(const Mat4& b) const
    {
        return (!((*this) == b));
    };

    inline Mat4 Mat4::Translate(const Vec3& a)
    {
        Mat4 out;

        out[3][0] = a.x;
        out[3][1] = a.y;
        out[3][2] = a.z;

        return (out);
    };

    inline Mat4 Mat4::Scale(const Vec3& a)
    {
        Mat4 out;

        out[0][0] = a.x;
        out[1][1] = a.y;
        out[2][2] = a.z;

        return (out);
    };

    inline Mat4 Mat4::QuatToMatrix(float x, float y, float z, float w)
    {
        Mat4 out;

        const float x2 = x + x;
        const float y2 = y + y;
        const float z2 = z + z;

        const float xx = x * x2;
        const float xy = x * y2;
        const float xz = x * z2;

        const float yy = y * y2;
        const float yz = y * z2;
        const float zz = z * z2;

        const float wx = w * x2;
        const float wy = w * y2;
        const float wz = w * z2;

        out.data[0][0] = 1.0f - (yy + zz);
        out.data[0][1] = xy + wz;
        out.data[0][2] = xz - wy;
        out.data[0][3] = 0.0f;

        out.data[1][0] = xy - wz;
        out.data[1][1] = 1.0f - (xx + zz);
        out.data[1][2] = yz + wx;
        out.data[1][3] = 0.0f;

        out.data[2][0] = xz + wy;
        out.data[2][1] = yz - wx;
        out.data[2][2] = 1.0f - (xx + yy);
        out.data[2][3] = 0.0f;

        out.data[3][0] = 0;
        out.data[3][1] = 0;
        out.data[3][2] = 0;
        out.data[3][3] = 1.0f;

        return (out);
    };

    inline Vec4 Mat4::GetColumn(int index) const
    {
        if (index == 0) return (Vec4(data[0][0], data[1][0], data[2][0], data[3][0]));
        if (index == 1) return (Vec4(data[0][1], data[1][1], data[2][1], data[3][1]));
        if (index == 2) return (Vec4(data[0][2], data[1][2], data[2][2], data[3][2]));
                        return (Vec4(data[0][3], data[1][3], data[2][3], data[3][3]));
    };

    inline void Mat4::SetColumn(int index, const Vec4& c)
    {
        data[0][index] = c.x;
        data[1][index] = c.y;
        data[2][index] = c.z;
        data[3][index] = c.w;
    };

    inline Vec4 Mat4::GetRow(int index) const
    {
        if (index == 0) return (Vec4(data[0][0], data[0][1], data[0][2], data[0][3]));
        if (index == 1) return (Vec4(data[1][0], data[1][1], data[1][2], data[1][3]));
        if (index == 2) return (Vec4(data[2][0], data[2][1], data[2][2], data[2][3]));
                        return (Vec4(data[3][0], data[3][1], data[3][2], data[3][3]));
    };

    inline void Mat4::SetRow(int index, const Vec4& r)
    {
        data[index][0] = r.x;
        data[index][1] = r.y;
        data[index][2] = r.z;
        data[index][3] = r.w;
    };

    inline Vec3 Mat4::GetPosition(void) const
    {
        return (Vec3(data[0][3], data[1][3], data[2][3]));
    };

    inline Vec3 Mat4::MultiplyPoint(const Vec3& pts)
    {
        Vec3 out;
        float w;

        out.x = data[0][0] * pts.x + data[0][1] * pts.y + data[0][2] * pts.z + data[0][3];
        out.y = data[1][0] * pts.x + data[1][1] * pts.y + data[1][2] * pts.z + data[1][3];
        out.z = data[2][0] * pts.x + data[2][1] * pts.y + data[2][2] * pts.z + data[2][3];
        w =     data[3][0] * pts.x + data[3][1] * pts.y + data[3][2] * pts.z + data[3][3];
        w = 1.0F / w;
        out *= w;
        return (out);
    };

    inline Vec3 Mat4::MultiplyPoint3x4(const Vec3& pts)
    {
        Vec3 out;

        out.x = data[0][0] * pts.x + data[0][1] * pts.y + data[0][2] * pts.z + data[0][3];
        out.y = data[1][0] * pts.x + data[1][1] * pts.y + data[1][2] * pts.z + data[1][3];
        out.z = data[2][0] * pts.x + data[2][1] * pts.y + data[2][2] * pts.z + data[2][3];
        return (out);
    };

    inline Vec3 Mat4::MultiplyVector(const Vec3& v)
    {
        Vec3 out;

        out.x = data[0][0] * v.x + data[0][1] * v.y + data[0][2] * v.z;
        out.y = data[1][0] * v.x + data[1][1] * v.y + data[1][2] * v.z;
        out.z = data[2][0] * v.x + data[2][1] * v.y + data[2][2] * v.z;
        return (out);
    };
};

const Mat4 Mat4::zero       = Mat4(Vec4(0.0F), Vec4(0.0F), Vec4(0.0F), Vec4(0.0F));
const Mat4 Mat4::identity   = Mat4();

std::ostream& operator<<(std::ostream& os, const Mat4& m)
{
    os << m.data[0][0] << '\t' << m.data[0][1] << '\t' << m.data[0][2] << '\t' << m.data[0][3] << '\n';
    os << m.data[1][0] << '\t' << m.data[1][1] << '\t' << m.data[1][2] << '\t' << m.data[1][3] << '\n';
    os << m.data[2][0] << '\t' << m.data[2][1] << '\t' << m.data[2][2] << '\t' << m.data[2][3] << '\n';
    os << m.data[3][0] << '\t' << m.data[3][1] << '\t' << m.data[3][2] << '\t' << m.data[3][3];
    return (os);
};
