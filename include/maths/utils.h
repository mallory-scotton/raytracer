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

#define PI 3.14159265358979323846f

#include <cmath>
#include <algorithm>
#include "config.h"

struct Math
{
    public:
        /**
         * @brief Converts radians to degrees.
         *
         * @param radians Angle in radians.
         *
         * @return Angle in degrees.
         */
        static inline float Degrees(float radians)
        {
            return (radians * (180.0F / PI));
        };

        /**
         * @brief Converts degrees to radians.
         *
         * @param degrees Angle in degrees.
         *
         * @return Angle in radians.
         */
        static inline float Radians(float degrees)
        {
            return (degrees * (PI / 180.0F));
        };

        /**
         * @brief Clamps a value between a minimum and maximum value.
         *
         * @param x The value to clamp.
         * @param min The minimum value.
         * @param max The maximum value.
         *
         * @return The clamped value.
         */
        static inline float Clamp(float x, float min, float max)
        {
            return (std::min(max, std::max(x, min)));
        };

        /**
         * @brief Clamps a value between 0 and 1.
         *
         * @param x The value to clamp.
         *
         * @return The clamped value.
         */
        static inline float Clamp01(float x)
        {
            return (Clamp(x, 0.0F, 1.0F));
        };

        /**
         * @brief Returns the sign of a value.
         *
         * @param x The value.
         *
         * @return -1 if x is negative, 1 otherwise.
         */
        static inline float Sign(float x)
        {
            return ((x < 0.0F) ? -1.0F : 1.0F);
        };

        /**
         * @brief Repeats a value within a specified length.
         *
         * @param t The value to repeat.
         * @param length The length within which to repeat the value.
         *
         * @return The repeated value.
         */
        static inline float Repeat(float t, float length)
        {
            return (Clamp(t - floorf(t / length) * length, 0.0F, length));
        };

        /**
         * @brief Ping-pongs a value between 0 and length.
         *
         * @param t The value to ping-pong.
         * @param length The length within which to ping-pong the value.
         *
         * @return The ping-ponged value.
         */
        static inline float PingPong(float t, float length)
        {
            t = Repeat(t, length * 2.0F);
            return (length - fabsf(t - length));
        };

        /**
         * @brief Linearly interpolates between two values.
         *
         * @param a The start value.
         * @param b The end value.
         * @param t The interpolation value (0-1).
         *
         * @return The interpolated value.
         */
        static inline float Lerp(float a, float b, float t)
        {
            return (a + (b - a) * Clamp01(t));
        };

        /**
         * @brief Linearly interpolates between two values without clamping.
         *
         * @param a The start value.
         * @param b The end value.
         * @param t The interpolation value.
         *
         * @return The interpolated value.
         */
        static inline float LerpUnclamped(float a, float b, float t)
        {
            return (a + (b - a) * t);
        };

        /**
         * @brief Linearly interpolates between two angles.
         *
         * @param a The start angle.
         * @param b The end angle.
         * @param t The interpolation value (0-1).
         *
         * @return The interpolated angle.
         */
        static inline float LerpAngle(float a, float b, float t)
        {
            float delta = Repeat((b - a), 360.0F);

            if (delta > 180.0F) delta -= 360.0F;
            return (a + delta * Clamp01(t));
        };

        /**
         * @brief Moves a value towards a target value by a maximum delta.
         *
         * @param current The current value.
         * @param target The target value.
         * @param maxDelta The maximum change that should be applied.
         *
         * @return The updated value.
         */
        static inline float MoveTowards(float current, float target, float maxDelta)
        {
            if (fabsf(target - current) <= maxDelta) return (target);
            return (current * Sign(target - current) * maxDelta);
        };

        /**
         * @brief Smoothly interpolates between two values.
         *
         * @param from The start value.
         * @param to The end value.
         * @param t The interpolation value (0-1).
         *
         * @return The interpolated value.
         */
        static inline float SmoothStep(float from, float to, float t)
        {
            t = Clamp01(t);
            t = -2.0F * t * t * t + 3.0F * t * t;
            return (to * t + from * (1.0F - t));
        };

        /**
         * @brief Applies gamma correction to a value.
         *
         * @param value The value to apply gamma correction to.
         * @param absmax The maximum absolute value.
         * @param gamma The gamma value.
         *
         * @return The gamma-corrected value.
         */
        static inline float Gamma(float value, float absmax, float gamma)
        {
            bool negative = value < 0.0F;
            float absval = fabsf(value);

            if (absval > absmax) return (negative ? -absval : absval);

            float result = powf(absval / absmax, gamma) * absmax;
            return (negative ? -result : result);
        };

        /**
         * @brief Determines if two values are approximately equal.
         *
         * @param a The first value.
         * @param b The second value.
         *
         * @return True if the values are approximately equal, false otherwise.
         */
        static inline bool Approximately(float a, float b)
        {
            return (fabsf(b - a) < std::max(0.000001F * std::max(fabsf(a), fabsf(b)), Epsilon * 8.0F));
        };

        /**
         * @brief Calculates the linear parameter that produces a value within the range [a, b].
         *
         * @param a The start value.
         * @param b The end value.
         * @param t The value to be normalized.
         *
         * @return The normalized value.
         */
        static inline float InverseLerp(float a, float b, float t)
        {
            if (a != b) return (Clamp01((t - a) / (b - a)));
            return (0.0F);
        };

        /**
         * @brief Calculates the shortest difference between two angles.
         *
         * @param current The current angle.
         * @param target The target angle.
         *
         * @return The difference between the angles.
         */
        static inline float DeltaAngle(float current, float target)
        {
            float delta = Repeat((target - current), 360.0F);

            if (delta > 180.0F) delta -= 360.0F;
            return (delta);
        };

        static const float Epsilon;
        static const float Pi;
        static const float Tau;
};

const float Math::Epsilon   = 1.4001298E-45;
const float Math::Pi        = PI;
const float Math::Tau       = (PI * 2.0F);
