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

#include "AnnotationPropertiesFactory.h"

namespace kImageAnnotator {

AnnotationPropertiesFactory::AnnotationPropertiesFactory()
{
    mConfig = Config::instance();
}

AnnotationProperties *AnnotationPropertiesFactory::createProperties(ToolTypes toolType) const
{
    auto properties = createPropertiesObject(toolType);

    setColor(properties, toolType);
	setTextColor(properties, toolType);
	setSize(properties, toolType);
	setFill(properties, toolType);
	setShadowEnabled(properties);

    return properties;
}

AnnotationProperties* AnnotationPropertiesFactory::createPropertiesObject(ToolTypes toolType) const
{
	switch (toolType) {
		case ToolTypes::Pen:
		case ToolTypes::Marker:
			return new AnnotationPathProperties();
		default:
			return new AnnotationProperties();
	}
}

void AnnotationPropertiesFactory::setColor(AnnotationProperties *properties, ToolTypes toolType) const
{
    auto color = mConfig->toolColor(toolType);

    if (toolType == ToolTypes::Marker) {
        color.setAlpha(120);
    }

    properties->setColor(color);
}

void AnnotationPropertiesFactory::setTextColor(AnnotationProperties *properties, ToolTypes toolType) const
{
    properties->setTextColor(mConfig->toolTextColor(toolType));
}

void AnnotationPropertiesFactory::setSize(AnnotationProperties *properties, ToolTypes toolType) const
{
    auto size = mConfig->toolSize(toolType);

    if (toolType == ToolTypes::Marker) {
        size = size * 3;
    }

    properties->setSize(size);
}

void AnnotationPropertiesFactory::setFill(AnnotationProperties *properties, ToolTypes toolType) const
{
    properties->setFillType(mConfig->toolFillType(toolType));
}

void AnnotationPropertiesFactory::setShadowEnabled(AnnotationProperties *properties) const
{
    properties->setShadowEnabled(mConfig->itemShadowEnabled());
}

} // namespace kImageAnnotator
