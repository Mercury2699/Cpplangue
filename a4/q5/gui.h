#include "observer.h"
#include "subject.h"
#include "window.h"
#include "state.h"
#include "info.h"
#include "cell.h"


class GraphicsDisplay : public Observer<Info, State> {
    Xwindow w;
    size_t gridSize = 0;

    public:
    GraphicsDisplay(size_t);
    void notify(Subject<Info, State> &whoFrom) override;
};



