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

struct Mathf
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

        /**
         * @brief Returns the absolute value of a floating-point number.
         *
         * @param x The floating-point number.
         *
         * @return The absolute value of x.
         */
        static inline float Abs(float x)
        {
            return (std::fabs(x));
        };

        /**
         * @brief Returns the smaller of two floating-point numbers.
         *
         * @param a The first number.
         * @param b The second number.
         *
         * @return The smaller of a and b.
         */
        static inline float Min(float a, float b)
        {
            return ((float)std::min(a, b));
        };

        /**
         * @brief Returns the smallest of three floating-point numbers.
         *
         * @param a The first number.
         * @param b The second number.
         * @param c The third number.
         *
         * @return The smallest of a, b, and c.
         */
        static inline float Min(float a, float b, float c)
        {
            return ((float)std::min({a, b, c}));
        };

        /**
         * @brief Returns the smallest of a list a floating-point numbers;
         *
         * @param l The list of numbers.
         *
         * @return The smallest of the list.
         */
        static inline float Min(std::initializer_list<float> l)
        {
            return ((float)std::min(l));
        };

        /**
         * @brief Returns the larger of two floating-point numbers.
         *
         * @param a The first number.
         * @param b The second number.
         *
         * @return The larger of a and b.
         */
        static inline float Max(float a, float b)
        {
            return ((float)std::max(a, b));
        };

        /**
         * @brief Returns the largest of three floating-point numbers.
         *
         * @param a The first number.
         * @param b The second number.
         * @param c The third number.
         *
         * @return The largest of a, b, and c.
         */
        static inline float Max(float a, float b, float c)
        {
            return ((float)std::max({a, b, c}));
        };

        /**
         * @brief Returns the larger of a list a floating-point numbers;
         *
         * @param l The list of numbers.
         *
         * @return The larger of the list.
         */
        static inline float Max(std::initializer_list<float> l)
        {
            return ((float)std::max(l));
        };

        /**
         * @brief Returns the sine of a floating-point angle in radians.
         *
         * @param f The angle in radians.
         *
         * @return The sine of the angle.
         */
        static inline float Sin(float f)
        {
            return ((float)std::sin(f));
        };

        /**
         * @brief Returns the cosine of a floating-point angle in radians.
         *
         * @param f The angle in radians.
         *
         * @return The cosine of the angle.
         */
        static inline float Cos(float f)
        {
            return ((float)std::cos(f));
        };

        /**
         * @brief Returns the tangent of a floating-point angle in radians.
         *
         * @param f The angle in radians.
         *
         * @return The tangent of the angle.
         */
        static inline float Tan(float f)
        {
            return ((float)std::tan(f));
        };

        /**
         * @brief Returns the arcsine of a floating-point value.
         *
         * @param f The value.
         *
         * @return The arcsine of the value.
         */
        static inline float Asin(float f)
        {
            return ((float)std::asin(f));
        };

        /**
         * @brief Returns the arccosine of a floating-point value.
         *
         * @param f The value.
         *
         * @return The arccosine of the value.
         */
        static inline float Acos(float f)
        {
            return ((float)std::acos(f));
        };

        /**
         * @brief Returns the arctangent of a floating-point value.
         *
         * @param f The value.
         *
         * @return The arctangent of the value.
         */
        static inline float Atan(float f)
        {
            return ((float)std::atan(f));
        };

        /**
         * @brief Returns the arctangent of the quotient of two values.
         *
         * @param y The numerator.
         * @param x The denominator.
         *
         * @return The arctangent of y/x.
         */
        static inline float Atan2(float y, float x)
        {
            return ((float)std::atan2(y, x));
        };

        /**
         * @brief Returns the square root of a floating-point value.
         *
         * @param f The value.
         *
         * @return The square root of the value.
         */
        static inline float Sqrt(float f)
        {
            return ((float)std::sqrt(f));
        };

        /**
         * @brief Returns the value of a floating-point base raised to a power.
         *
         * @param f The base.
         * @param p The exponent.
         *
         * @return The result of raising f to the power p.
         */
        static inline float Pow(float f, float p)
        {
            return ((float)std::pow(f, p));
        };

        /**
         * @brief Returns the exponential function of a floating-point value.
         *
         * @param power The exponent.
         *
         * @return The exponential function of the value.
         */
        static inline float Exp(float power)
        {
            return ((float)std::exp(power));
        };

        /**
         * @brief Returns the base-2 exponential function of a floating-point value.
         *
         * @param power The exponent.
         *
         * @return The base-2 exponential function of the value.
         */
        static inline float Exp2(float power)
        {
            return ((float)std::exp2(power));
        };

        /**
         * @brief Returns the natural logarithm of a floating-point value.
         *
         * @param f The value.
         *
         * @return The natural logarithm of the value.
         */
        static inline float Log(float f)
        {
            return ((float)std::log(f));
        };

        /**
         * @brief Returns the base-2 logarithm of a floating-point value.
         *
         * @param f The value.
         *
         * @return The base-2 logarithm of the value.
         */
        static inline float Log2(float f)
        {
            return ((float)std::log2(f));
        };

        /**
         * @brief Returns the base-10 logarithm of a floating-point value.
         *
         * @param f The value.
         *
         * @return The base-10 logarithm of the value.
         */
        static inline float Log10(float f)
        {
            return ((float)std::log10(f));
        };

        /**
         * @brief Returns the smallest integer value greater than or equal to the given floating-point value.
         *
         * @param f The value.
         *
         * @return The smallest integer value greater than or equal to f.
         */
        static inline float Ceil(float f)
        {
            return ((float)std::ceil(f));
        };

        /**
         * @brief Returns the smallest integer greater than or equal to the given floating-point value.
         *
         *  @param f The value.
         *
         *  @return The smallest integer greater than or equal to f.
         */
        static inline int CeilToInt(float f)
        {
            return ((int)Ceil(f));
        };

        /**
         * @brief Returns the largest integer value less than or equal to the given floating-point value.
         *
         * @param f The value.
         *
         * @return The largest integer value less than or equal to f.
         */
        static inline float Floor(float f)
        {
            return ((float)std::floor(f));
        };

        /**
         * @brief Returns the largest integer less than or equal to the given floating-point value.
         *
         * @param f The value.
         *
         * @return The largest integer less than or equal to f.
         */
        static inline int FloorToInt(float f)
        {
            return ((int)Floor(f));
        };

        /**
         * @brief Rounds the given floating-point value to the nearest integer.
         *
         * @param f The value.
         *
         * @return The rounded value.
         */
        static inline float Round(float f)
        {
            return ((float)std::round(f));
        };

        /**
         * @brief Rounds the given floating-point value to the nearest integer and returns it as an int.
         *
         * @param f The value.
         *
         * @return The rounded value as an int.
         */
        static inline int RoundToInt(float f)
        {
            return ((int)Round(f));
        };

        /**
         * @brief Smoothly dampens a value towards a target over time.
         *
         * @param current The current value.
         * @param target The target value.
         * @param currentVelocity The current velocity, modified by the function.
         * @param smoothTime The time to reach the target.
         * @param maxSpeed The maximum speed of movement.
         * @param deltaTime The time step.
         *
         * @return The new value after smoothing.
         */
        static inline float SmoothDamp(float current, float target, float& currentVelocity, float smoothTime, float maxSpeed, float deltaTime)
        {
            smoothTime = Max(0.0001F, smoothTime);
            float omega = 2.0F / smoothTime;

            float x = omega * deltaTime;
            float exp = 1.0F  / (1.0F + x + 0.48F * x * x + 0.235F * x * x * x);
            float change = current - target;
            float originalTo = target;

            float maxChange = maxSpeed * smoothTime;
            change = Clamp(change, -maxChange, maxChange);
            target = current - change;

            float temp = (currentVelocity + omega * change) * deltaTime;
            currentVelocity = (currentVelocity - omega * temp) * exp;
            float output = target + (change + temp) * exp;

            if ((originalTo - current > 0.0F) == (output > originalTo))
            {
                output = originalTo;
                currentVelocity = (output - originalTo) / deltaTime;
            }
            return (output);
        };

        /**
         * @brief Rounds the given value to the nearest multiple of the specified rounding value.
         *
         * @param value The value to round.
         * @param roundingValue The rounding value.
         *
         * @return The value rounded to the nearest multiple of roundingValue.
         */
        static inline float RoundToMulitpleOf(float value, float roundingValue)
        {
            if (roundingValue == 0)
                return (value);
            return (Round(value / roundingValue) * roundingValue);
        };

        /**
         * @brief Returns the closest power of ten to the given positive number.
         *
         * @param positiveNumber The positive number.
         *
         * @return The closest power of ten.
         */
        static inline float GetClosestPowerOfTen(float positiveNumber)
        {
            if (positiveNumber <= 0)
                return (1.0F);
            return (Pow(10.0F, RoundToInt(Log10(positiveNumber))));
        };

        static const float Epsilon;
        static const float Pi;
        static const float Tau;
};

const float Mathf::Epsilon   = 1.4001298E-45;
const float Mathf::Pi        = PI;
const float Mathf::Tau       = (PI * 2.0F);
