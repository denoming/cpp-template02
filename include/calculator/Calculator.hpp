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
 * @file Calculator.hpp
 *
 * @brief [Some brief information]
 *
 * @ingroup [PackageName]
 * (Note: this needs exactly one @defgroup somewhere)
 *
 * @author [Author]
 * Contact: [Contacts (e.g. email)]
 */

#pragma once

#include "calculator/CalculatorExport.hpp"

#include <memory>

namespace My {

/**
 * [Class definition]
 */
class CALC_EXPORT Calculator {
public:
    Calculator();

    ~Calculator();

    /**
     * [Method definition]
     * @param arg1 [...]
     * @param arg2 [...]
     * @return [...]
     */
    int
    add(int arg1, int arg2);

    /**
     * [Method definition]
     * @param arg1 [...]
     * @param arg2 [...]
     * @return [...]
     */
    float
    add(float arg1, float arg2);

private:
    std::unique_ptr<class CalculatorImpl> _impl;
};

} // namespace My
