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

#ifndef ANNOTATIONMULTIITEMRESIZERTEST_H
#define ANNOTATIONMULTIITEMRESIZERTEST_H

#include <QtTest>

#include "../src/annotations/modifiers/AnnotationMultiItemResizer.h"
#include "../src/annotations/items/AnnotationLine.h"

class AnnotationMultiItemResizerTest : public QObject
{
    Q_OBJECT
private slots:
    void TestGrabHandle_Should_GrabHandle_When_ProvidedPointIsAtHandlePosition();
    void TestGrabHandle_Should_NotGrabHandle_When_ProvidedPointIsNotAtHandlePosition();
    void TestGrabHandle_Should_MoveResizeHandle_When_HandleGrabbed();
    void TestGrabHandle_Should_OnlyMoveOneResizeHandle_When_MultipleItemsInList();
    void TestReleaseHandle_Should_ReleaseHandle();
    void TestHasItemsAttached_Should_ReturnFalse_When_NoItemsInList();
    void TestHasItemsAttached_Should_ReturnTrue_When_ItemsInList();
};

#endif // ANNOTATIONMULTIITEMRESIZERTEST_H