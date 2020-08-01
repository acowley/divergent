// Copyright (c) 2020 Anthony Cowley. All rights reserved.

// Redistribution and use in source and binary forms, with or without modification,
// are permitted provided that the following conditions are met:

// 1. Redistributions of source code must retain the above copyright notice,
// this list of conditions and the following disclaimer.

// 2. Redistributions in binary form must reproduce the above copyright notice,
// this list of conditions and the following disclaimer in the documentation
// and/or other materials provided with the distribution.

// 3. Neither the name of the copyright holder nor the names of its contributors
// may be used to endorse or promote products derived from this software without
// specific prior written permission.

// THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS "AS IS"
// AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT LIMITED TO, THE
// IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR A PARTICULAR PURPOSE
// ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT HOLDER OR CONTRIBUTORS BE
// LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL, SPECIAL, EXEMPLARY, OR CONSEQUENTIAL
// DAMAGES (INCLUDING, BUT NOT LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR
// SERVICES; LOSS OF USE, DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER
// CAUSED AND ON ANY THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY,
// OR TORT (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE
// USE OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE.

#include "generate_samples.h"

#include "vtkColorTransferFunction.h"

#include "vtkSmartPointer.h"
#define VTK_CREATE(type, name) \
  vtkSmartPointer<type> name = vtkSmartPointer<type>::New()

/// Produce a C array definition of 8-bit RGBA color values for a
/// color map. This array can be directly loaded into a 1D texture for
/// graphics applications.
void palette_header(const char *palName, vtkColorTransferFunction *map) {
  using namespace std;
  stringstream fname;
  fname << palName << ".h";
  ofstream f(fname.str());
  f << "const uint8_t " << palName << "[] = {\\" << endl;
  const uint palLength = 1024;
  for(uint i = 0; i < palLength; ++i) {
    double *color = map->GetColor(double(i) / double(palLength));
    f << uint(color[0] * 255.0) << ", " << uint(color[1] * 255.0) << ", "
      << uint(color[2] * 255.0) << ", 255";
    if(i < 1023) {
      f << ",\\" << endl;
    } else {
      f << "};" << endl;
    }
  }
}

int main(int, char **) {
  VTK_CREATE(vtkColorTransferFunction, blue2orange);
  blue2orange->SetColorSpaceToDiverging();

  // Add a blue point
  // blue2orange->AddRGBPoint(0.0, 0.217, 0.525, 0.910);
  // blue2orange->AddRGBPoint(0.0, 0.0431373, 0.164706, 0.639216);
  blue2orange->AddRGBPoint(0.0, 0.06, 0.04, 0.4);

  // Add an orange point
  // blue2orange->AddRGBPoint(1.0, 0.706, 0.016, 0.150);
  blue2orange->AddRGBPoint(1.0, 0.811765, 0.345098, 0.113725);

  // Save an image of the color map
  generate_bar("Blue2OrangeBar.png", blue2orange);

  // Save a C header defining the palette as a 1D array of RGBA
  // values.
  palette_header("blueToOrange", blue2orange);
  
  return 0;
}
