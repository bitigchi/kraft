/***************************************************************************
              postiontagdialog.h  - Edit tags of positions
                             -------------------
    begin                : Aug 2008
    copyright            : (C) 2008 by Klaas Freitag
    email                : freitag@kde.org
 ***************************************************************************/

/***************************************************************************
 *
 *
 *   This program is free software; you can redistribute it and/or modify  *
 *   it under the terms of the GNU General Public License as published by  *
 *   the Free Software Foundation; either version 2 of the License, or     *
 *   (at your option) any later version.                                   *
 *                                                                         *
 ***************************************************************************/

#include <qcombobox.h>
#include <qwidget.h>
#include <qvbox.h>
#include <qlabel.h>
#include <qlistview.h>

#include <kdialogbase.h>
#include <kdebug.h>
#include <klocale.h>
#include <kcombobox.h>
#include <ktextedit.h>
#include <klineedit.h>

#include "positiontagdialog.h"
#include "defaultprovider.h"


PositionTagDialog::PositionTagDialog( QWidget *parent )
  : KDialogBase( parent, "POSITION_TAG_DIALOG", true, i18n( "Edit Item Tags" ),
                 Ok | Cancel )
{
  QWidget *w = makeVBoxMainWidget();
  ( void ) new QLabel( i18n( "Item Tags:" ), w );
  mListView = new KListView( w );
  mListView->setItemMargin( 3 );
  mListView->setAlternateBackground( QColor( "#dffdd0" ) );
  mListView->header()->hide();
  mListView->setRootIsDecorated( false );
  mListView->setSelectionMode( QListView::Single );
  mListView->addColumn( i18n( "Tag" ) );
  // FIXME: Display help if a item is selection
  mListView->setSelectionMode( QListView::NoSelection );
  // mFilterHeader = new FilterHeader( mListView, w );
  // mFilterHeader->showCount( false );

}

PositionTagDialog::~PositionTagDialog()
{

}

void PositionTagDialog::setTags( const QStringList& tags )
{
  for ( QStringList::ConstIterator it = tags.begin(); it != tags.end(); ++it ) {
    QCheckListItem *item = new QCheckListItem( mListView, *it, QCheckListItem::CheckBox );
    mItemMap[*it] = item;
  }
}

void PositionTagDialog::setPositionTags( const QStringList& tags )
{
  for ( QStringList::ConstIterator it = tags.begin(); it != tags.end(); ++it ) {
    if ( mItemMap.contains( *it ) ) {
      QCheckListItem *item = mItemMap[*it];
      if( item ) {
        item->setOn( true );
      }
    }
  }
}

QStringList PositionTagDialog::getSelectedTags()
{
  QStringList re;

   QListViewItemIterator it( mListView, QListViewItemIterator::Checked );
   while ( it.current() ) {
     re << ( *it )->text( 0 );
     ++it;
   }
   return re;
}


#include "positiontagdialog.moc"