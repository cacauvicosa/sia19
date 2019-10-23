# pyglet: a cross-platform windowing and multimedia library for Python.
# pip install pyglet

import pyglet

music = pyglet.resource.media('Bamboo.wav')
music.play()

pyglet.app.run()
quit()

