import csv
import sys


def main():

    titles = []
    people = []

# opens file

    if len(sys.argv) > 3:
        exit()
    else:
        database = sys.argv[1]
        sequence = sys.argv[2]

# reads database in titles and people variables

    with open(database, 'r') as csvfile:
        file = csv.reader(csvfile)

        titles = next(file)

        for row in file:
            people.append(row)

# reads sequence into dna variable

    seq = open(sequence, 'r')
    dna = seq.read()
    #seqs = (letter for letter in dna if letter != 'A')

# finds longest match of each STR in DNA sequence

    titles.pop(0)
    STRs = []

    for STR in titles:
        STRs.append(longest_match(dna, STR))

# checks database for profiel match

    for x in range(len(STRs)):
        i = 0
        for y in range(len(people[x]))[1::]:
            if str(STRs[y-1]) == people[x][y]:
                i = i + 1
            if i == len(people[x]) - 1:
                break
        else:
            continue
        break

    if i == len(people[x]) - 1:
        print(people[x][0])
    else:
        print("No Match")

    return


def longest_match(sequence, subsequence):
    """Returns length of longest run of subsequence in sequence."""

    # Initialize variables
    longest_run = 0
    subsequence_length = len(subsequence)
    sequence_length = len(sequence)

    # Check each character in sequence for most consecutive runs of subsequence
    for i in range(sequence_length):

        # Initialize count of consecutive runs
        count = 0

        # Check for a subsequence match in a "substring" (a subset of characters) within sequence
        # If a match, move substring to next potential match in sequence
        # Continue moving substring and checking for matches until out of consecutive matches
        while True:

            # Adjust substring start and end
            start = i + count * subsequence_length
            end = start + subsequence_length

            # If there is a match in the substring
            if sequence[start:end] == subsequence:
                count += 1

            # If there is no match in the substring
            else:
                break

        # Update most consecutive matches found
        longest_run = max(longest_run, count)

    # After checking for runs at each character in seqeuence, return longest run found
    return longest_run


main()