# Qt-logical-units
A simple C++ class with sample project that demonstrates using logical units in QML

The UI class manages the logical units-to-pixels conversion and is registered for QML usage in main.cpp.

Set the dpi property to your display's exact DPI to get correct scaling.

For an overview of how this works, see my 2014 Qt Dev Days lightning talk presentation:
  https://www.qtdeveloperdays.com/sites/default/files/presentation_pdf/Using%20SVG%20Images%20with%20QML%20v2.pdf
The first part discusses SVG images, but starting on page 7 I get into using real-world units instead of pixels. My example says it took 3 hours to convert an existing screen from pixels to physical units -- that screen was very complex. These days I write everything from the ground up using points, inches or millimeters (depending on client).

Tips:
 - Never specify pixels; always multiply by the UI.pt, UI.mm, UI.cm or UI.in conversion constant to get the pixels
 - When specifying Text size, never use font.pointSize. Always use font.pixelSize and set to some value times UI.pt

This class gets tricky to use when you are writing a desktop app -- In that case use Qt to get the logical pixels per inch and set the dpi property.


 
 
