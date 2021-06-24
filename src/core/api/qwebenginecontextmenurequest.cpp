/****************************************************************************
**
** Copyright (C) 2020 The Qt Company Ltd.
** Contact: https://www.qt.io/licensing/
**
** This file is part of the QtWebEngine module of the Qt Toolkit.
**
** $QT_BEGIN_LICENSE:LGPL$
** Commercial License Usage
** Licensees holding valid commercial Qt licenses may use this file in
** accordance with the commercial license agreement provided with the
** Software or, alternatively, in accordance with the terms contained in
** a written agreement between you and The Qt Company. For licensing terms
** and conditions see https://www.qt.io/terms-conditions. For further
** information use the contact form at https://www.qt.io/contact-us.
**
** GNU Lesser General Public License Usage
** Alternatively, this file may be used under the terms of the GNU Lesser
** General Public License version 3 as published by the Free Software
** Foundation and appearing in the file LICENSE.LGPL3 included in the
** packaging of this file. Please review the following information to
** ensure the GNU Lesser General Public License version 3 requirements
** will be met: https://www.gnu.org/licenses/lgpl-3.0.html.
**
** GNU General Public License Usage
** Alternatively, this file may be used under the terms of the GNU
** General Public License version 2.0 or (at your option) the GNU General
** Public license version 3 or any later version approved by the KDE Free
** Qt Foundation. The licenses are as published by the Free Software
** Foundation and appearing in the file LICENSE.GPL2 and LICENSE.GPL3
** included in the packaging of this file. Please review the following
** information to ensure the GNU General Public License requirements will
** be met: https://www.gnu.org/licenses/gpl-2.0.html and
** https://www.gnu.org/licenses/gpl-3.0.html.
**
** $QT_END_LICENSE$
**
****************************************************************************/

#include "qwebenginecontextmenurequest.h"
#include "qwebenginecontextmenurequest_p.h"

QT_BEGIN_NAMESPACE

/*!
    \class QWebEngineContextMenuRequest
    \since 6.2
    \brief The QWebEngineContextMenuRequest class provides request for populating or extending a context menu with actions.

    \inmodule QtWebEngineCore

    QWebEngineContextMenuRequest is returned by QWebEngineView::lastContextMenuRequest() after a context menu event,
    and contains information about where the context menu event took place. This is also in the context
    in which any context specific QWebEnginePage::WebAction will be performed.
*/

/*!
    \enum QWebEngineContextMenuRequest::MediaType
    \readonly
    \since 6.2

    This enum describes the media type of the context menu request if any.

    \value MediaTypeNone The context is not a media type.
    \value MediaTypeImage The context is an image element.
    \value MediaTypeVideo The context is a video element.
    \value MediaTypeAudio The context is an audio element.
    \value MediaTypeCanvas The context is a canvas element.
    \value MediaTypeFile The context is a file.
    \value MediaTypePlugin The context is a plugin element.
*/

/*!
    \enum QWebEngineContextMenuRequest::EditFlag
    \readonly
    \since 6.2

    The available edit operations in the current context menu request.

    \value  CanUndo Undo is available.
    \value  CanRedo Redo is available.
    \value  CanCut Cut is available.
    \value  CanCopy Copy is available.
    \value  CanPaste Paste is available.
    \value  CanDelete Delete is available.
    \value  CanSelectAll Select All is available.
    \value  CanTranslate Translate is available.
    \value  CanEditRichly Context is richly editable.
*/

/*!
    \enum QWebEngineContextMenuRequest::MediaFlag
    \readonly
    \since 6.2

    The current media element's status and its available operations.
    \c MediaNone if the selected web page content is not a media element.

    \value  MediaInError An error occurred.
    \value  MediaPaused Media is paused.
    \value  MediaMuted Media is muted.
    \value  MediaLoop Media can be looped.
    \value  MediaCanSave Media can be saved.
    \value  MediaHasAudio Media has audio.
    \value  MediaCanToggleControls Media can show controls.
    \value  MediaControls Media controls are shown.
    \value  MediaCanPrint Media is printable.
    \value  MediaCanRotate Media is rotatable.
*/

/*!
     \internal
*/
QWebEngineContextMenuRequest::QWebEngineContextMenuRequest(
        QWebEngineContextMenuRequestPrivate *request)
    : d(request)
{
}

/*!
    Destroys the context menu request.
*/
QWebEngineContextMenuRequest::~QWebEngineContextMenuRequest() = default;

/*!
    Returns the position of the context menu request, usually the mouse
    position where the context menu event was triggered.
*/
QPoint QWebEngineContextMenuRequest::position() const
{
    return d->m_position;
}

/*!
    Returns the selected text of the context menu request.
*/
QString QWebEngineContextMenuRequest::selectedText() const
{
    return d->m_selectedText;
}

/*!
    Returns the text of a link if the context menu request was requested for a link.
*/
QString QWebEngineContextMenuRequest::linkText() const
{
    return d->m_linkText;
}

/*!
    Returns the URL of a link if the menu context request is a link.
    It is not guaranteed to be a valid URL.
*/
QUrl QWebEngineContextMenuRequest::linkUrl() const
{
    return d->m_unfilteredLinkUrl;
}

/*!
    If the context menu request is a media element, returns the URL of that media.
*/
QUrl QWebEngineContextMenuRequest::mediaUrl() const
{
    return d->m_mediaUrl;
}

/*!
    Returns the type of the media element or \c MediaTypeNone
    if the context menu requestis not a media element.
*/
QWebEngineContextMenuRequest::MediaType QWebEngineContextMenuRequest::mediaType() const
{
    return static_cast<QWebEngineContextMenuRequest::MediaType>(d->m_mediaType);
}

/*!
    Returns \c true if the context menu request is editable by the user;
    otherwise returns \c false.
*/
bool QWebEngineContextMenuRequest::isContentEditable() const
{
    return d->m_isEditable;
}

/*!
    If the menu context request is a word considered misspelled by the spell-checker,
    returns the misspelled word.

    For possible replacements of the word, see spellCheckerSuggestions().
*/
QString QWebEngineContextMenuRequest::misspelledWord() const
{
    return d->m_misspelledWord;
}


/*!
    If the menu context request is a word considered misspelled by the spell-checker,
    returns a list of suggested replacements for misspelledWord().
*/
QStringList QWebEngineContextMenuRequest::spellCheckerSuggestions() const
{
    return d->m_spellCheckerSuggestions;
}

/*!
  TODO: needs api in page
*/
bool QWebEngineContextMenuRequest::isAccepted() const
{
    return d->m_accepted;
}

/*!
  TODO: needs api in page
*/
void QWebEngineContextMenuRequest::setAccepted(bool accepted)
{
    d->m_accepted = accepted;
}

/*!
    Returns the current media element's status and its available operations.
    \c MediaNone if the selected web page content is not a media element.
*/
QWebEngineContextMenuRequest::MediaFlags QWebEngineContextMenuRequest::mediaFlags() const
{
    return static_cast<QWebEngineContextMenuRequest::MediaFlags>(d->m_mediaFlags);
}

/*!
    Returns the available edit operations in the current context
    or \c CanDoNone if no actions are available.
*/
QWebEngineContextMenuRequest::EditFlags QWebEngineContextMenuRequest::editFlags() const
{
    return static_cast<QWebEngineContextMenuRequest::EditFlags>(d->m_editFlags);
}

/*!
  \internal
*/
QUrl QWebEngineContextMenuRequest::filteredLinkUrl() const
{
    return d->m_filteredLinkUrl;
}

/*!
  \internal
*/
QString QWebEngineContextMenuRequest::altText() const
{
    return d->m_altText;
}

/*!
  \internal
*/
QString QWebEngineContextMenuRequest::titleText() const
{
    return d->m_titleText;
}

/*!
  \internal
*/
QUrl QWebEngineContextMenuRequest::referrerUrl() const
{
    return !d->m_frameUrl.isEmpty() ? d->m_frameUrl : d->m_pageUrl;
}

/*!
  \internal
*/
QtWebEngineCore::ReferrerPolicy QWebEngineContextMenuRequest::referrerPolicy() const
{
    return d->m_referrerPolicy;
}

/*!
  \internal
*/
QString QWebEngineContextMenuRequest::suggestedFileName() const
{
    return d->m_suggestedFileName;
}

/*!
  \internal
*/
bool QWebEngineContextMenuRequest::hasImageContent() const
{
    return d->m_hasImageContent;
}

QT_END_NAMESPACE
