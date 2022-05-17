#include "CPlotLine.h"

CPlotLine::CPlotLine(const QString& label,
                     const QPen&    lineColor) : mLabel(label),
                                                 mLineColor(lineColor)
{

}
CPlotLine::CPlotLine(CPlotLine&& rhs) : mLabel(std::move(rhs.mLabel)),
                                        mLineColor(std::move(rhs.mLineColor))
{
    //TODO Check move-Constructor
}
