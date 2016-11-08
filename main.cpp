#define RUN_TESTS

#include <iostream>

#include "entity/Cell.h"
#include "entity/Map.h"
#include "view/MapView.h"
#include "controller/MapEditorController.h"
#include "utils/IOUtils.h"
#include "view/EditorView.h"
#include "entity/repo/MapRepository.h"


using namespace std;

int main()
{

    MapRepository* mapRepo = MapRepository::instance();



    EditorView::editorMenu(mapRepo);

    return 0;
}