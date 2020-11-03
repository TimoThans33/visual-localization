#include <gst/gst.h>

int main(int argc, char *argv[])
{
    GstElement *pipeline;
    GstBus *bus;
    GstMessage *msg;

    /* Initialize GStreamer */
    /* This must always be your fist GStreamer command. Among other things, gst_init():
     - Initializes all internal structures
     - Checks what plug-ins are available
     - Executes any command-line option intended for GStreamer
    If you always pass your command=line parameters argc and argv to gst_init, you application will
    automatically benefit from the gstreamer standard command-line options */
    gst_init (&argc, &argv);

    /* Build the pipeline */
    /* gst_parse_launch:
    Media travels from the 'source' elements (the producers), down to the 'sink' elements (the consumers)
    passsing through series of intermediate elements performing al kinds of tasks. This is called a pipeline
    >> This function takes textual representation of a pipeline and turns it into an actual pipeline.
    playbin:
    is a special element that acts both as a source and as a sink and is the whole pipeline.
    */ 
    pipeline = gst_parse_launch("playbin uri=https://www.freedesktop.org/software/gstreamer-sdk/data/media/sintel_trailer-480p.webm",
      NULL);
    
    /* Start playing */
    /*
    Every GStreamer element has an associated state, which you can more or less think of as the play/pause button.
    gst_element_set_state (pipeline, GST_STATE_PLAYING);

    /* Wait until error or EOS */
    bus = gst_element_get_bus(pipeline);
    msg = gst_bus_timed_pop_filtered (bus, GST_CLOCK_TIME_NONE, (GstMessageType)(GST_MESSAGE_ERROR | GST_MESSAGE_EOS));

    /* Free resources */
    if (msg != NULL)
        gst_message_unref (msg);
    gst_object_unref (bus);
    gst_element_set_state (pipeline, GST_STATE_NULL);
    gst_object_unref (pipeline);
    return 0;
}