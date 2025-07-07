is_sunny = True
have_umbrella= False

print("Should go outside?","YES" if ((is_sunny | have_umbrella)==True) else "NO")
print("Should you carry the umbrella?","YES" if is_sunny==False else "NO")
