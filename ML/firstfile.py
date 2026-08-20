import pyttsx3

engine = pyttsx3.init()

# List available voices
voices = engine.getProperty('voices')
for voice in voices:
    print(voice.id, voice.name)

# Change voice (male/female, different accents)
engine.setProperty('voice', voices[1].id)  # pick a different index
engine.say("This is a different voice!")
engine.runAndWait()

engine = pyttsx3.init()

engine.setProperty('rate', 50)   # speed (default ~200)
engine.setProperty('volume', 0.5) # volume (0.0 to 1.0)

engine.say("Speaking slower and softer now.")
engine.runAndWait()
