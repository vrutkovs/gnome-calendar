/* gcal-event.h
 *
 * Copyright (C) 2016 Georges Basile Stavracas Neto <georges.stavracas@gmail.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#ifndef GCAL_EVENT_H
#define GCAL_EVENT_H

#include <glib-object.h>
#include <gtk/gtk.h>
#include <libecal/libecal.h>
#include <libedataserver/libedataserver.h>

G_BEGIN_DECLS

#define GCAL_TYPE_EVENT (gcal_event_get_type())

G_DECLARE_FINAL_TYPE (GcalEvent, gcal_event, GCAL, EVENT, GObject)

GcalEvent*           gcal_event_new                              (ESource            *source,
                                                                  ECalComponent      *component);

gboolean             gcal_event_get_all_day                      (GcalEvent          *self);

void                 gcal_event_set_all_day                      (GcalEvent          *self,
                                                                  gboolean            all_day);

GdkRGBA*             gcal_event_get_color                        (GcalEvent          *self);

void                 gcal_event_set_color                        (GcalEvent          *self,
                                                                  GdkRGBA            *color);

ECalComponent*       gcal_event_get_component                    (GcalEvent          *self);

GDateTime*           gcal_event_get_date_end                     (GcalEvent          *self);

void                 gcal_event_set_date_end                     (GcalEvent          *self,
                                                                  GDateTime          *dt);

GDateTime*           gcal_event_get_date_start                   (GcalEvent          *self);

void                 gcal_event_set_date_start                   (GcalEvent          *self,
                                                                  GDateTime          *dt);

const gchar*         gcal_event_get_description                  (GcalEvent          *self);

void                 gcal_event_set_description                  (GcalEvent          *self,
                                                                  const gchar        *description);

gboolean             gcal_event_has_alarms                       (GcalEvent          *self);

const gchar*         gcal_event_get_location                     (GcalEvent          *self);

void                 gcal_event_set_location                     (GcalEvent          *self,
                                                                  const gchar        *location);

ESource*             gcal_event_get_source                       (GcalEvent          *self);

void                 gcal_event_set_source                       (GcalEvent          *self,
                                                                  ESource            *source);

const gchar*         gcal_event_get_summary                      (GcalEvent          *self);

void                 gcal_event_set_summary                      (GcalEvent          *self,
                                                                  const gchar        *summary);

GTimeZone*           gcal_event_get_timezone                     (GcalEvent          *self);

void                 gcal_event_set_timezone                     (GcalEvent          *self,
                                                                  GTimeZone          *timezone);

const gchar*         gcal_event_get_uid                          (GcalEvent          *self);

/* Utilities */

gboolean             gcal_event_is_multiday                      (GcalEvent          *self);

gint                 gcal_event_compare                          (GcalEvent          *event1,
                                                                  GcalEvent          *event2);

gint                 gcal_event_compare_with_current             (GcalEvent          *event1,
                                                                  GcalEvent          *event2,
                                                                  time_t             *current_time);

G_END_DECLS

#endif /* GCAL_EVENT_H */
