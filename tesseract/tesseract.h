#include <tesseract/baseapi.h>
#include <leptonica/allheaders.h>
#include <iostream>

void optical_character_recognition(std::string& path, std::string& language) {

        tesseract::TessBaseAPI api {};

        if (api.Init(nullptr, language.c_str())) {
                std::cerr << "Could not initialize tesseract.\n";
                std::exit(1);
        }

        Pix *image = pixRead(path.c_str());
        api.SetImage(image);
        std::string out = api.GetUTF8Text();
        std::cout << "OCR output: " << out << "\n";

        api.End();
        pixDestroy(&image);
}
