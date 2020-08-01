{ stdenv, nix-gitignore, cmake, vtk }:
stdenv.mkDerivation {
  pname = "divergent";
  version = "0.0";
  src = nix-gitignore.gitignoreSource [] ./.;
  nativeBuildInputs = [ cmake ];
  buildInputs = [ vtk ];
  meta = {
    description = "Diverging Color Map Creation Library and Tools";
    homepage = https://github.com/acowley/divergent;
    license = stdenv.lib.licenses.bsd3;
    platforms = stdenv.lib.platforms.all;
  };  
}
