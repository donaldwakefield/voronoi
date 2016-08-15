SOURCES += main.cxx Model.cxx SketchView.cxx SketchScene.cxx
HEADERS += Model.h SketchView.h SketchScene.h

INCLUDEPATH += ../Primitives ../Utils

QMAKE_CLEAN += $(TARGET) $(QMAKE_TARGET)

sources.files = $$SOURCES \
    $$HEADERS \
    $$RESOURCES \
    $$FORMS \
    sketch.pro
