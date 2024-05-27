/**
 * [Company Name]
 * See COPYRIGHT file at the top of the source tree.
 *
 * This product includes software developed by the
 * [Project Name] ([Project URL]).
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the License.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT WARRANTY OF ANY KIND; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE. See the
 * MIT License for more details.
 *
 * You should have received a copy of the MIT License along with this
 * program. If not, see <[URL to legal notice]>.
 */

/**
 * @file Calculator.cpp
 *
 * @brief [Some brief information]
 *
 * @ingroup [PackageName]
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author [Author]
 * Contact: [Contacts (e.g. email)]
 */

#include "calculator/Calculator.hpp"

#include "CalculatorImpl.hpp"

namespace My {

Calculator::Calculator()
    : _impl{new CalculatorImpl}
{
}

Calculator::~Calculator() = default;

int
Calculator::add(int arg1, int arg2)
{
    return _impl->add(arg1, arg2);
}

float
Calculator::add(float arg1, float arg2)
{
    return _impl->add(arg1, arg2);
}

} // namespace My
