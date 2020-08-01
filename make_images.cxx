// -*- c++ -*-
//
// Copyright (c) 2009-2020 National Technology & Engineering Solutions of Sandia, LLC (NTESS), Kitware Inc.
// Sandia National Laboratories, New Mexico PO Box 5800 Albuquerque, NM 87185
//
// Under the terms of Contract DE-NA0003525 with NTESS, the U.S. Government
// retains certain rights in this software.
//
// This software is released under the 3-Clause BSD License
//
// Redistribution and use in source and binary forms, with or without
// modification, are permitted provided that the following conditions are met:
//
// 1. Redistributions of source code must retain the above copyright notice,
//    this list of conditions and the following disclaimer.
//
// 2. Redistributions in binary form must reproduce the above copyright notice,
//    this list of conditions and the following disclaimer in the documentation
//    and/or other materials provided with the distribution.
//
// 3. Neither the name of Kitware nor the names of any contributors may be used
//    to endorse or promote products derived from this software without specific
//    prior written permission.
//
// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE AUTHORS OR CONTRIBUTORS BE LIABLE FOR
// ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
// OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.
//

#include "generate_samples.h"

#include "vtkColorTransferFunction.h"

#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

int main(int, char **)
{
  VTK_CREATE(vtkColorTransferFunction, rainbow);
  rainbow->SetColorSpaceToHSV();
  rainbow->HSVWrapOff();
  rainbow->AddHSVPoint(0.0, 0.66667, 1.0, 1.0);
  rainbow->AddHSVPoint(1.0, 0.0, 1.0, 1.0);
  generate_bar("RainbowBar.png", rainbow);
//   generate_radial("RainbowRadial.png", rainbow);
//   generate_discontinuity("RainbowDiscontinuity.png", rainbow);
  generate_spatial_contrast_sensitivity("RainbowSpatialContrast.png", rainbow);
  generate_hf_noise("RainbowHfNoise.png", rainbow);
  generate_lf_sensitivity("RainbowLfSensitivity.png", rainbow);

  VTK_CREATE(vtkColorTransferFunction, grayscale);
  grayscale->SetColorSpaceToRGB();
  grayscale->AddRGBPoint(0.0, 0.0, 0.0, 0.0);
  grayscale->AddRGBPoint(1.0, 1.0, 1.0, 1.0);
  generate_bar("GrayscaleBar.png", grayscale);
//   generate_discontinuity("GrayscaleDiscontinuity.png", grayscale);
  generate_locality("GrayscaleLocality.png", grayscale);
  generate_spatial_contrast_sensitivity("GrayscaleSpatialContrast.png",
                                        grayscale);
  generate_hf_noise("GrayscaleHfNoise.png", grayscale);
  generate_lf_sensitivity("GrayscaleLfSensitivity.png", grayscale);

  VTK_CREATE(vtkColorTransferFunction, blackbody);
  blackbody->SetColorSpaceToRGB();
  blackbody->AddRGBPoint(0.0, 0.0, 0.0, 0.0);
  blackbody->AddRGBPoint(0.4, 0.9, 0.0, 0.0);
  blackbody->AddRGBPoint(0.8, 0.9, 0.9, 0.0);
  blackbody->AddRGBPoint(1.0, 1.0, 1.0, 1.0);
//   generate_bar("BlackBodyBar.png", blackbody);
  generate_locality("BlackBodyLocality.png", blackbody);
  generate_spatial_contrast_sensitivity("BlackBodySpatialContrast.png",
                                        blackbody);
  generate_hf_noise("BlackBodyHfNoise.png", blackbody);
  generate_lf_sensitivity("BlackBodyLfSensitivity.png", blackbody);

  VTK_CREATE(vtkColorTransferFunction, cool2warm);
  cool2warm->SetColorSpaceToDiverging();
  cool2warm->AddRGBPoint(0.0, 0.230, 0.299, 0.754);
  cool2warm->AddRGBPoint(1.0, 0.706, 0.016, 0.150);
  generate_bar("Cool2WarmBar.png", cool2warm);
//   generate_discontinuity("Cool2WarmDiscontinuity.png", cool2warm);
  generate_spatial_contrast_sensitivity("Cool2WarmSpatialContrast.png",
                                        cool2warm);
  generate_radial("Cool2WarmRadial.png", cool2warm);
  generate_hf_noise("Cool2WarmHfNoise.png", cool2warm);
  generate_lf_sensitivity("Cool2WarmLfSensitivity.png", cool2warm);

  VTK_CREATE(vtkColorTransferFunction, cool2warmLab);
  cool2warmLab->SetColorSpaceToLab();
  cool2warmLab->AddRGBPoint(0.0, 0.230, 0.299, 0.754);
  cool2warmLab->AddRGBPoint(0.5, 0.865, 0.865, 0.865);
  cool2warmLab->AddRGBPoint(1.0, 0.706, 0.016, 0.150);
  generate_radial("Cool2WarmLabRadial.png", cool2warmLab);

  VTK_CREATE(vtkColorTransferFunction, green2red);
  green2red->SetColorSpaceToLab();
  green2red->AddRGBPoint(0.0, 0.000, 0.499, 0.000);
  green2red->AddRGBPoint(1.0, 0.780, 0.225, 0.129);
  generate_bar("Green2RedBar.png", green2red);
  generate_spatial_contrast_sensitivity("Green2RedSpatialContrast.png",
                                        green2red);
  generate_hf_noise("Green2RedHfNoise.png", green2red);
  generate_lf_sensitivity("Green2RedLfSensitivity.png", green2red);

  VTK_CREATE(vtkColorTransferFunction, cyan2mauve);
  cyan2mauve->SetColorSpaceToLab();
  cyan2mauve->AddRGBPoint(0.0, 0.0, 0.6, 0.75);
  cyan2mauve->AddRGBPoint(1.0, 0.768, 0.467, 0.341);
  generate_bar("Cyan2MauveBar.png", cyan2mauve);

  VTK_CREATE(vtkColorTransferFunction, blue2yellow);
  blue2yellow->SetColorSpaceToRGB();
  blue2yellow->AddRGBPoint(0.0, 0.040, 0.040, 0.950);
  blue2yellow->AddRGBPoint(1.0, 0.950, 0.950, 0.040);
//   generate_bar("Blue2YellowBar.png", blue2yellow);
  generate_spatial_contrast_sensitivity("Blue2YellowSpatialContrast.png",
                                        blue2yellow);
  generate_hf_noise("Blue2YellowHfNoise.png", blue2yellow);
  generate_lf_sensitivity("Blue2YellowLfSensitivity.png", blue2yellow);

  VTK_CREATE(vtkColorTransferFunction, purple2orange);
  purple2orange->SetColorSpaceToDiverging();
  purple2orange->AddRGBPoint(0.0, 0.436, 0.308, 0.631);
  purple2orange->AddRGBPoint(1.0, 0.759, 0.334, 0.046);
  generate_bar("Purple2OrangeBar.png", purple2orange);

  VTK_CREATE(vtkColorTransferFunction, green2purple);
  green2purple->SetColorSpaceToDiverging();
  green2purple->AddRGBPoint(0.0, 0.085, 0.532, 0.201);
  green2purple->AddRGBPoint(1.0, 0.436, 0.308, 0.631);
  generate_bar("Green2PurpleBar.png", green2purple);

  VTK_CREATE(vtkColorTransferFunction, blue2tan);
  blue2tan->SetColorSpaceToDiverging();
  blue2tan->AddRGBPoint(0.0, 0.217, 0.525, 0.910);
  blue2tan->AddRGBPoint(1.0, 0.677, 0.492, 0.093);
  generate_bar("Blue2TanBar.png", blue2tan);

  VTK_CREATE(vtkColorTransferFunction, green2redDiv);
  green2redDiv->SetColorSpaceToDiverging();
  green2redDiv->AddRGBPoint(0.0, 0.085, 0.532, 0.201);
  green2redDiv->AddRGBPoint(1.0, 0.758, 0.214, 0.233);
  generate_bar("Green2RedDivBar.png", green2redDiv);

  return 0;
}
