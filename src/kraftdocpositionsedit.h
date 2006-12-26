#ifndef KRAFTDOCPOSITIONSEDIT_H
#define KRAFTDOCPOSITIONSEDIT_H

#include "docheader.h"
#include "kraftdocedit.h"

class KraftViewScroll;
class KPushButton;

class KraftDocPositionsEdit : public KraftDocEdit
{
  Q_OBJECT
public:
  KraftDocPositionsEdit( QWidget* );

  // FIXME: Remove access to internal widgets
  KraftViewScroll *positionScroll() { return m_positionScroll; }
  KPushButton *catalogToggle() { return mCatalogToggle; }

signals:
  void addPositionClicked();
  void catalogToggled( bool enabled );

private:
  KraftViewScroll *m_positionScroll;
  KPushButton *mCatalogToggle;  
};

#endif
