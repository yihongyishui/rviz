/*
 * Copyright (c) 2010, Willow Garage, Inc.
 * Copyright (c) 2018, Bosch Software Innovations GmbH.
 * All rights reserved.
 *
 * Redistribution and use in source and binary forms, with or without
 * modification, are permitted provided that the following conditions are met:
 *
 *     * Redistributions of source code must retain the above copyright
 *       notice, this list of conditions and the following disclaimer.
 *     * Redistributions in binary form must reproduce the above copyright
 *       notice, this list of conditions and the following disclaimer in the
 *       documentation and/or other materials provided with the distribution.
 *     * Neither the name of the Willow Garage, Inc. nor the names of its
 *       contributors may be used to endorse or promote products derived from
 *       this software without specific prior written permission.
 *
 * THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
 * AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
 * IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
 * ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT OWNER OR CONTRIBUTORS BE
 * LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR
 * CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF
 * SUBSTITUTE GOODS OR SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS
 * INTERRUPTION) HOWEVER CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN
 * CONTRACT, STRICT LIABILITY, OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE)
 * ARISING IN ANY WAY OUT OF THE USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE
 * POSSIBILITY OF SUCH DAMAGE.
 */

#ifndef RVIZ_DEFAULT_PLUGINS__DISPLAYS__MARKER__MARKERS__TRIANGLE_LIST_MARKER_HPP_
#define RVIZ_DEFAULT_PLUGINS__DISPLAYS__MARKER__MARKERS__TRIANGLE_LIST_MARKER_HPP_

#include <string>

#include <OgreMaterial.h>
#include <OgreSharedPtr.h>

#include "marker_base.hpp"

namespace Ogre
{
class SceneNode;
class ManualObject;
}

namespace rviz_default_plugins
{
namespace displays
{
namespace markers
{

class TriangleListMarker : public MarkerBase
{
public:
  TriangleListMarker(
    MarkerDisplay * owner, rviz_common::DisplayContext * context, Ogre::SceneNode * parent_node);
  ~TriangleListMarker() override;

  S_MaterialPtr getMaterials() override;

protected:
  void onNewMessage(
    const MarkerConstSharedPtr & old_message, const MarkerConstSharedPtr & new_message) override;

  Ogre::ManualObject * manual_object_;
  Ogre::MaterialPtr material_;
  std::string material_name_;

private:
  bool wrongNumberOfPoints(const MarkerConstSharedPtr & new_message);
  void printWrongNumberOfPointsError(size_t num_points);

  void initializeManualObject(const MarkerConstSharedPtr & new_message);
  void updateManualObject(
    const MarkerConstSharedPtr & old_message, const MarkerConstSharedPtr & new_message) const;

  void beginManualObject(
    const MarkerConstSharedPtr & old_message,
    const MarkerConstSharedPtr & new_message) const;
  bool fillManualObjectAndDetermineAlpha(MarkerConstSharedPtr new_message) const;
  void updateMaterial(const MarkerConstSharedPtr & new_message, bool any_vertex_has_alpha) const;

  bool hasVertexColors(MarkerConstSharedPtr new_message) const;
  bool hasFaceColors(MarkerConstSharedPtr new_message) const;
};

}  // namespace markers
}  // namespace displays
}  // namespace rviz_default_plugins

#endif  // RVIZ_DEFAULT_PLUGINS__DISPLAYS__MARKER__MARKERS__TRIANGLE_LIST_MARKER_HPP_
