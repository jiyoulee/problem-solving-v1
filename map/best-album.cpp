#include <unordered_map>
#include <queue>
#include <string>
#include <vector>

using namespace std;

vector<int> solution(vector<string> genres, vector<int> plays) {
    unordered_map<string, int> reference_genre;				// A reference for play count of genres.
    priority_queue<tuple<int, int, int>> reference_song;	// A reference for song rankings.
    tuple<int, int, int> song;
    vector<int> answer;

	/*
	 * Get the total number of plays for each genre.
	 */
    for (int i = 0; i < genres.size(); i++) {
        reference_genre[genres[i]] += plays[i];
    }

	/*
	 * Rank songs in order of genre popularity, song popularity, and ID.
	 */
    for (int i = 0; i < plays.size(); i++) {
        reference_song.push({reference_genre[genres[i]], plays[i], (-1) * i});
    }

	/*
	 * Find the top song/top two songs from each genre.
	 */
    while (!reference_song.empty()) {
        song = reference_song.top();
        answer.push_back((-1) * get<2>(song));
        reference_song.pop();
        if (!reference_song.empty() && get<0>(reference_song.top()) == get<0>(song)) {
            answer.push_back((-1) * get<2>(reference_song.top()));
            do {
                reference_song.pop();
            } while (!reference_song.empty() && get<0>(reference_song.top()) == get<0>(song));
        }
    }
    return answer;
}