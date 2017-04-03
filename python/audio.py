import simpleaudio as sa

wave_obj = sa.WaveObject.from_wave_file("Sound/Snares/Snare (1).wav")
play_obj = wave_obj.play()
play_obj.wait_done()
