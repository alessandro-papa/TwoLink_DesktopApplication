#ifndef CPLOTLINE_H
#define CPLOTLINE_H
#include <QString>
#include <QPen>

class CPlotLine
{
public:
    CPlotLine(const QString& label,
              const QPen&    lineColor);
    CPlotLine(CPlotLine&& rhs);
    CPlotLine(const CPlotLine&) = default;
    CPlotLine& operator=(const CPlotLine&) = default;
    ~CPlotLine() = default;
private:
    QString mLabel;
    QPen    mLineColor;

    friend class CPlot;
};

#endif // CPLOTLINE_H
