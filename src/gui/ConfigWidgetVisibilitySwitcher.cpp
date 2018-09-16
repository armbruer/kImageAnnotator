/*
 * Copyright (C) 2018 Damir Porobic <damir.porobic@gmx.com>
 *
 * This program is free software; you can redistribute it and/or modify
 * it under the terms of the GNU Lesser General Public License as published by
 * the Free Software Foundation; either version 2 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU Lesser General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 51 Franklin Street, Fifth Floor,
 * Boston, MA 02110-1301, USA.
 */

#include "ConfigWidgetVisibilitySwitcher.h"

namespace kImageAnnotator {

ConfigWidgetVisibilitySwitcher::ConfigWidgetVisibilitySwitcher()
{
    mColorWidget = nullptr;
    mTextColorWidget = nullptr;
    mSizeWidget = nullptr;
    mFillWidget = nullptr;

    mCurrentTool = ToolTypes::Select;
}

void ConfigWidgetVisibilitySwitcher::setCurrentTool(ToolTypes tool)
{
    if (mCurrentTool == tool) {
        return;
    }

    mCurrentTool = tool;
    updateVisibility();
}

void ConfigWidgetVisibilitySwitcher::setOutlineColorWidget(QWidget *widget)
{
    mColorWidget = widget;
    updateVisibility();
}

void ConfigWidgetVisibilitySwitcher::setForegroundColorWidget(QWidget *widget)
{
    mTextColorWidget = widget;
    updateVisibility();
}

void ConfigWidgetVisibilitySwitcher::setSizeWidget(QWidget *widget)
{
    mSizeWidget = widget;
    updateVisibility();
}

void ConfigWidgetVisibilitySwitcher::setFillWidget(QWidget *widget)
{
    mFillWidget = widget;
    updateVisibility();
}

void ConfigWidgetVisibilitySwitcher::updateVisibility()
{
    switch (mCurrentTool) {
        case ToolTypes::Select:
            setColorWidgetVisibility(false);
            setTextColorWidgetVisibility(false);
            setSizeWidgetVisibility(false);
            setFillWidgetVisibility(false);
            break;
        case ToolTypes::Pen:
        case ToolTypes::Marker:
            setColorWidgetVisibility(true);
            setTextColorWidgetVisibility(false);
            setSizeWidgetVisibility(true);
            setFillWidgetVisibility(false);
            break;
        case ToolTypes::Line:
        case ToolTypes::Arrow:
            setColorWidgetVisibility(true);
            setTextColorWidgetVisibility(false);
            setSizeWidgetVisibility(true);
            setFillWidgetVisibility(false);
            break;
        case ToolTypes::Ellipse:
        case ToolTypes::Rect:
            setColorWidgetVisibility(true);
            setTextColorWidgetVisibility(false);
            setSizeWidgetVisibility(true);
            setFillWidgetVisibility(true);
            break;
        case ToolTypes::Number:
            setColorWidgetVisibility(true);
            setTextColorWidgetVisibility(true);
            setSizeWidgetVisibility(true);
            setFillWidgetVisibility(false);
        case ToolTypes::Text:
            setColorWidgetVisibility(true);
            setTextColorWidgetVisibility(true);
            setSizeWidgetVisibility(true);
            setFillWidgetVisibility(true);
            break;
        default:
            qCritical("Unknown tooltype in ConfigWidgetVisibilitySwitcher");
    }
}

void ConfigWidgetVisibilitySwitcher::setColorWidgetVisibility(bool enabled)
{
    if (mColorWidget) {
        mColorWidget->setEnabled(enabled);
    }
}

void ConfigWidgetVisibilitySwitcher::setTextColorWidgetVisibility(bool enabled)
{
    if (mTextColorWidget) {
        mTextColorWidget->setEnabled(enabled);
    }
}

void ConfigWidgetVisibilitySwitcher::setSizeWidgetVisibility(bool enabled)
{
    if (mSizeWidget) {
        mSizeWidget->setEnabled(enabled);
    }
}

void ConfigWidgetVisibilitySwitcher::setFillWidgetVisibility(bool enabled)
{
    if (mFillWidget) {
        mFillWidget->setEnabled(enabled);
    }
}

} // namespace kImageAnnotator