/* -*- Mode: C; tab-width: 8; indent-tabs-mode: t; c-basic-offset: 8; c-indent-level: 8 -*- */
/*
 *  Copyright (C) 2000-2003 Marco Pesenti Gritti
 *
 *  This program is free software; you can redistribute it and/or modify
 *  it under the terms of the GNU General Public License as published by
 *  the Free Software Foundation; either version 2, or (at your option)
 *  any later version.
 *
 *  This program is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 *  GNU General Public License for more details.
 *
 *  You should have received a copy of the GNU General Public License
 *  along with this program; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.
 *
 */

#ifndef EV_ASYNC_RENDERER_H
#define EV_ASYNC_RENDERER_H

#include <glib-object.h>
#include <glib.h>
#include <gdk/gdkpixbuf.h>

G_BEGIN_DECLS

#define EV_TYPE_ASYNC_RENDERER	          (ev_async_renderer_get_type ())
#define EV_ASYNC_RENDERER(o)		  (G_TYPE_CHECK_INSTANCE_CAST ((o), EV_TYPE_ASYNC_RENDERER, EvAsyncRenderer))
#define EV_ASYNC_RENDERER_IFACE(k)	  (G_TYPE_CHECK_CLASS_CAST((k), EV_TYPE_ASYNC_RENDERER, EvAsyncRendererIface))
#define EV_IS_ASYNC_RENDERER(o)		  (G_TYPE_CHECK_INSTANCE_TYPE ((o), EV_TYPE_ASYNC_RENDERER))
#define EV_IS_ASYNC_RENDERER_IFACE(k)	  (G_TYPE_CHECK_CLASS_TYPE ((k), EV_TYPE_ASYNC_RENDERER))
#define EV_ASYNC_RENDERER_GET_IFACE(inst) (G_TYPE_INSTANCE_GET_INTERFACE ((inst), EV_TYPE_ASYNC_RENDERER, EvAsyncRendererIface))

typedef struct _EvAsyncRenderer	  EvAsyncRenderer;
typedef struct _EvAsyncRendererIface   EvAsyncRendererIface;

struct _EvAsyncRendererIface
{
	GTypeInterface base_iface;

	void	    (* render_finished) (EvAsyncRenderer *renderer,
					 GdkPixbuf       *pixbuf);

	void        (* render_pixbuf)   (EvAsyncRenderer *renderer,
					 int              page,
					 double           scale,
					 int              rotation);
};

GType		ev_async_renderer_get_type       (void);
void		ev_async_renderer_render_pixbuf  (EvAsyncRenderer *renderer,
				      	          int              page,
						  double           scale,
						  int              rotation);

G_END_DECLS

#endif