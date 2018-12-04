// ======================================================================== //
// Copyright 2009-2018 Intel Corporation                                    //
//                                                                          //
// Licensed under the Apache License, Version 2.0 (the "License");          //
// you may not use this file except in compliance with the License.         //
// You may obtain a copy of the License at                                  //
//                                                                          //
//     http://www.apache.org/licenses/LICENSE-2.0                           //
//                                                                          //
// Unless required by applicable law or agreed to in writing, software      //
// distributed under the License is distributed on an "AS IS" BASIS,        //
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied. //
// See the License for the specific language governing permissions and      //
// limitations under the License.                                           //
// ======================================================================== //

#pragma once

#include <ospray/ospray.h>

#ifdef __cplusplus
extern "C" {
#endif

typedef struct
{
  OSPGeometry geometry;
#ifdef __cplusplus
  osp::box3f bounds;
#else
  osp_box3f bounds;
#endif
} OSPTestingGeometry;

typedef struct
{
  OSPVolume volume;
#ifdef __cplusplus
  osp::box3f bounds;
#else
  osp_box3f bounds;
#endif
} OSPTestingVolume;

/* Create an OSPRay renderer with sensible defaults for testing */
OSPRenderer ospTestingNewRenderer(const char *type OSP_DEFAULT_VAL(= "scivis"));

/* Create an OSPRay geometry (from a registered name), with the given renderer
 * type to create materials */
OSPTestingGeometry ospTestingNewGeometry(const char *geom_type,
                                         const char *renderer_type
                                             OSP_DEFAULT_VAL(= "scivis"));

/* Create an OSPRay geometry (from a registered name) */
OSPTestingVolume ospTestingNewVolume(const char *geom_type);

/* Create an OSPRay perspective camera which looks at the center of the given
 * bounding box
 * 
 * NOTE: this only sets 'dir', 'pos', and 'up'
 */
#ifdef __cplusplus
OSPCamera ospTestingNewDefaultCamera(osp::box3f bounds);
#else
OSPCamera ospTestingNewDefaultCamera(osp_box3f bounds);
#endif

/* Create a list of lights, using a given preset name */
OSPData ospTestingNewLights(
    const char *lighting_set_name OSP_DEFAULT_VAL(= "ambient_only"));

#ifdef __cplusplus
}  // extern "C"
#endif