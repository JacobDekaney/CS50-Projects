from cs50 import *


def main():
    text = get_string("Text: ")
    letters = count_letters(text)
    words = count_words(text)
    sentences = count_sentences(text)
    grade = grade_level(letters, words, sentences)
    if grade < 1:
        print("Before Grade 1")
    elif grade > 16:
        print("Grade 16+")
    else:
        print("Grade", grade)


def count_letters(text):
    letters = 0

    for letter in text:
        if letter.isalpha():
            letters = letters + 1

    return letters


def count_words(text):
    words = 1

    for word in text:
        if word == ' ':
            words = words + 1

    return words


def count_sentences(text):
    sentences = 0

    for sentence in text:
        if sentence == '.' or sentence == '?' or sentence == '!':
            sentences = sentences + 1

    return sentences


def grade_level(letters, words, sentences):
    grade = 0
    L = 0
    S = 0

    L = (letters / words) * 100
    S = (sentences / words) * 100

    grade = .0588 * L - 0.296 * S - 15.8
    return round(grade)


main()