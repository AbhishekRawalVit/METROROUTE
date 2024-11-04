#include <iostream>
#include <vector>
#include <unordered_map>
#include <limits>
#include <set>
#include <queue>
#include <list>
#include <algorithm>
#include <string>

using namespace std;

struct Edge {
    string to;
    int weight;  // Travel time in minutes
    Edge(string t, int w) : to(t), weight(w) {}
};

struct Station {
    string name;
    list<Edge> connections;

    Station() {}  // Default constructor
    Station(string n) : name(n) {}
};

class MetroSystem {
private:
    unordered_map<string, Station> stations;

public:
    void addStation(const string& name) {
        if (stations.find(name) == stations.end()) {
            stations.emplace(make_pair(name, Station(name)));
        }
    }

    void addConnection(const string& from, const string& to, int weight) {
        if (stations.find(from) != stations.end() && stations.find(to) != stations.end()) {
            stations[from].connections.push_back(Edge(to, weight));
            stations[to].connections.push_back(Edge(from, weight));  // Assuming bidirectional connection
        }
    }

    void dijkstra(const string& source, const string& target) {
        unordered_map<string, int> dist;
        unordered_map<string, string> prev;
        priority_queue<pair<int, string>, vector<pair<int, string>>, greater<pair<int, string>>> pq;

        for (auto& station : stations) {
            dist[station.first] = numeric_limits<int>::max();
        }

        dist[source] = 0;
        pq.push({0, source});

        while (!pq.empty()) {
            string u = pq.top().second;
            pq.pop();

            cout << "Visiting: " << u << " with current dist: " << dist[u] << endl;

            if (u == target) break;

            for (const auto& neighbor : stations[u].connections) {
                string v = neighbor.to;
                int weight = neighbor.weight;
                int distanceThroughU = dist[u] + weight;

                if (distanceThroughU < dist[v]) {
                    dist[v] = distanceThroughU;
                    prev[v] = u;
                    pq.push({dist[v], v});

                    cout << "Updating: " << v << " to dist: " << dist[v] << " via " << u << endl;
                }
            }
        }

        vector<string> path;
        string step = target;
        while (step != source && prev.find(step) != prev.end()) {
            path.push_back(step);
            step = prev[step];
        }

        if (step == source) {
            path.push_back(source);
            reverse(path.begin(), path.end());

            cout << "Shortest path based on travel time from " << source << " to " << target << " is: \n";
            for (const auto& p : path) {
                cout << p << " -> ";
            }
            cout << "end" << endl;
            cout << "Total travel time: " << dist[target] << " minutes" << endl;
        } else {
            cout << "No path found from " << source << " to " << target << endl;
        }
    }


    void setupSystem() {
        // Add stations
        addStation("Adarsh Nagar");
        addStation("AIIMS");
        addStation("Akshardham");
        addStation("Anand Vihar ISBT");
        addStation("Arjan Garh");
        addStation("Arthala");
        addStation("Ashok Park Main");
        addStation("Ashram");
        addStation("Azadpur");
        addStation("Badarpur Border");
        addStation("Badkhal Mor");
        addStation("Bahadurgarh City");
        addStation("Barakhambha Road");
        addStation("Bata Chowk");
        addStation("Bhikaji Cama Place");
        addStation("Botanical Garden");
        addStation("Brigadier Hoshiyar Singh");
        addStation("Central Secretariat");
        addStation("Chandni Chowk");
        addStation("Chawri Bazar");
        addStation("Chhatarpur");
        addStation("Chirag Delhi");
        addStation("Civil Lines");
        addStation("Dabri Mor-Janakpuri South");
        addStation("Dashrath Puri");
        addStation("Delhi Aerocity");
        addStation("Delhi Cantonment");
        addStation("Delhi Gate");
        addStation("Dhaula Kuan");
        addStation("Dilshad Garden");
        addStation("Durgabai Deshmukh South Campus");
        addStation("Dwarka");
        addStation("Dwarka Mor");
        addStation("Dwarka Sector 8");
        addStation("Dwarka Sector 9");
        addStation("Dwarka Sector 10");
        addStation("Dwarka Sector 11");
        addStation("Dwarka Sector 12");
        addStation("Dwarka Sector 13");
        addStation("Dwarka Sector 14");
        addStation("Dwarka Sector 21");
        addStation("East Azad Nagar");
        addStation("East Vinod Nagar – Mayur Vihar-II");
        addStation("Escorts Mujesar");
        addStation("ESI Hospital");
        addStation("Ghevra");
        addStation("Ghitorni");
        addStation("Gokulpuri");
        addStation("Golf Course");
        addStation("Govind Puri");
        addStation("Greater Kailash");
        addStation("Green Park");
        addStation("GTB Nagar");
        addStation("Guru Dronacharya");
        addStation("Haiderpur");
        addStation("Harkesh Nagar Okhla");
        addStation("Hauz Khas");
        addStation("Hazrat Nizamuddin");
        addStation("Hindon");
        addStation("HUDA City Centre");
        addStation("IFFCO Chowk");
        addStation("INA");
        addStation("Inderlok");
        addStation("Indira Gandhi International Airport");
        addStation("Indraprastha");
        addStation("IP Extension");
        addStation("ITO");
        addStation("Jaffrabad");
        addStation("Jahangirpuri");
        addStation("Jama Masjid");
        addStation("Jamia Millia Islamia");
        addStation("Janakpuri East");
        addStation("Janakpuri West");
        addStation("Jangpura");
        addStation("Janpath");
        addStation("Jasola Apollo");
        addStation("Jasola Vihar Shaheen Bagh");
        addStation("Jawaharlal Nehru Stadium");
        addStation("Jhandewalan");
        addStation("Jhilmil");
        addStation("Johari Enclave");
        addStation("Jor Bagh");
        addStation("Kailash Colony");
        addStation("Kalindi Kunj");
        addStation("Kalkaji Mandir");
        addStation("Kanhaiya Nagar");
        addStation("Karkarduma");
        addStation("Karkarduma Court");
        addStation("Karol Bagh");
        addStation("Kashmere Gate");
        addStation("Kaushambi");
        addStation("Keshav Puram");
        addStation("Khan Market");
        addStation("Kirti Nagar");
        addStation("Krishna Nagar");
        addStation("Kohat Enclave");
        addStation("Lajpat Nagar");
        addStation("Lal Qila");
        addStation("Laxmi Nagar");
        addStation("Lok Kalyan Marg");
        addStation("Madipur");
        addStation("Maharaja Surajmal Stadium");
        addStation("Majlis Park");
        addStation("Major Mohit Sharma");
        addStation("Malviya Nagar");
        addStation("Mandawali – West Vinod Nagar");
        addStation("Mandi House");
        addStation("Mansarovar Park");
        addStation("Maujpur-Babarpur");
        addStation("Mayapuri");
        addStation("Mayur Vihar I");
        addStation("Mayur Vihar Extension");
        addStation("Mayur Vihar Pocket I");
        addStation("Mewala Maharajpur");
        addStation("MG Road");
        addStation("Model Town");
        addStation("Mohan Estate");
        addStation("Mohan Nagar");
        addStation("Moolchand");
        addStation("Moti Nagar");
        addStation("Mundka");
        addStation("Mundka Industrial Area");
        addStation("Munirka");
        addStation("Najafgarh");
        addStation("Nangli");
        addStation("Nangloi");
        addStation("Nangloi Railway station");
        addStation("Naraina Vihar");
        addStation("Nawada");
        addStation("Neelam Chowk Ajronda");
        addStation("Nehru Enclave");
        addStation("Nehru Place");
        addStation("Netaji Subhash Place");
        addStation("New Ashok Nagar");
        addStation("New Delhi");
        addStation("NHPC Chowk");
        addStation("Nirman Vihar");
        addStation("Noida City Centre");
        addStation("Noida Electronic City");
        addStation("Noida Sector 15");
        addStation("Noida Sector 16");
        addStation("Noida Sector 18");
        addStation("Noida Sector 34");
        addStation("Noida Sector 52");
        addStation("Noida Sector 59");
        addStation("Noida Sector 61");
        addStation("Noida Sector 62");
        addStation("Okhla Bird Sanctuary");
        addStation("Okhla NSIC");
        addStation("Okhla Vihar");
        addStation("Okhla");
        addStation("Old Faridabad");
        addStation("Palam");
        addStation("Panchsheel Park");
        addStation("Pandit Shree Ram Sharma");
        addStation("Paschim Vihar East");
        addStation("Paschim Vihar West");
        addStation("Patel Chowk");
        addStation("Patel Nagar");
        addStation("Peera Garhi");
        addStation("Pitam Pura");
        addStation("Pratap Nagar");
        addStation("Pragati Maidan");
        addStation("Preet Vihar");
        addStation("Pul Bangash");
        addStation("Punjabi Bagh");
        addStation("Punjabi Bagh West");
        addStation("Qutab Minar");
        addStation("R.K.Puram");
        addStation("Raja Nahar Singh");
        addStation("Raj Bagh");
        addStation("Rajdhani Park");
        addStation("Rajendra Place");
        addStation("Rajiv Chowk");
        addStation("Rajouri Garden");
        addStation("Ramakrishna Ashram Marg");
        addStation("Ramesh Nagar");
        addStation("Rithala");
        addStation("Rohini East");
        addStation("Rohini Sector 18");
        addStation("Rohini West");
        addStation("Sadar Bazaar Cantonment");
        addStation("Saket");
        addStation("Samaypur Badli");
        addStation("Sant Surdas (Sihi)");
        addStation("Sarai");
        addStation("Sarita Vihar");
        addStation("Sarojini Nagar");
        addStation("Satguru Ramsingh Marg");
        addStation("Sector 28");
        addStation("Seelampur");
        addStation("Shadipur");
        addStation("Shahdara");
        addStation("Shaheed Nagar");
        addStation("Shaheed Sthal");
        addStation("Shakurpur");
        addStation("Shalimar Bagh");
        addStation("Shankar Vihar");
        addStation("Shastri Nagar");
        addStation("Shastri Park");
        addStation("Shiv Vihar");
        addStation("Shivaji Park");
        addStation("Shivaji Stadium");
        addStation("Shyam Park");
        addStation("Sikandarpur");
        addStation("Sir Vishweshwaraiah Moti Bagh");
        addStation("South");
        addStation("Subhash Nagar");
        addStation("Sukhdev Vihar");
        addStation("Sultanpur");
        addStation("Supreme Court");
        addStation("Tagore Garden");
        addStation("Terminal 1-IGI Airport");
        addStation("Tikri Border");
        addStation("Tikri Kalan");
        addStation("Tilak Nagar");
        addStation("Tis Hazari");
        addStation("Trilokpuri Sanjay Lake");
        addStation("Tughlakabad");
        addStation("Udyog Bhawan");
        addStation("Udyog Nagar");
        addStation("Uttam Nagar East");
        addStation("Uttam Nagar West");
        addStation("Vaishali");
        addStation("Vasant Vihar");
        addStation("Vidhan Sabha");
        addStation("Vinobapuri");
        addStation("Vishwa Vidyalaya");
        addStation("Welcome");
        addStation("Yamuna Bank");

        int t=2;
        // Yellow Line Connections
        addConnection("Samaypur Badli", "Rohini Sector 18, 19", t);
        addConnection("Rohini Sector 18, 19", "Haiderpur Badli Mor", t);
        addConnection("Haiderpur Badli Mor", "Jahangirpuri", t);
        addConnection("Jahangirpuri", "Adarsh Nagar", t);
        addConnection("Adarsh Nagar", "Azadpur", t);
        addConnection("Azadpur", "Model Town", t);
        addConnection("Model Town", "GTB Nagar", t);
        addConnection("GTB Nagar", "Vishwa Vidyalaya", t);
        addConnection("Vishwa Vidyalaya", "Vidhan Sabha", t);
        addConnection("Vidhan Sabha", "Civil Lines", t);
        addConnection("Civil Lines", "Kashmere Gate", t);
        addConnection("Kashmere Gate", "Chandni Chowk", t);
        addConnection("Chandni Chowk", "Chawri Bazar", t);
        addConnection("Chawri Bazar", "New Delhi", t);
        addConnection("New Delhi", "Rajiv Chowk", t);
        addConnection("Rajiv Chowk", "Patel Chowk", t);
        addConnection("Patel Chowk", "Central Secretariat", t);
        addConnection("Central Secretariat", "Udyog Bhawan", t);
        addConnection("Udyog Bhawan", "Lok Kalyan Marg", t);
        addConnection("Lok Kalyan Marg", "Jor Bagh", t);
        addConnection("Jor Bagh", "INA", t);
        addConnection("INA", "AIIMS", t);
        addConnection("AIIMS", "Green Park", t);
        addConnection("Green Park", "Hauz Khas", t);
        addConnection("Hauz Khas", "Malviya Nagar", t);
        addConnection("Malviya Nagar", "Saket", t);
        addConnection("Saket", "Qutab Minar", t);
        addConnection("Qutab Minar", "Chhatarpur", t);
        addConnection("Chhatarpur", "Sultanpur", t);
        addConnection("Sultanpur", "Ghitorni", t);
        addConnection("Ghitorni", "Arjan Garh", t);
        addConnection("Arjan Garh", "Guru Dronacharya", t);
        addConnection("Guru Dronacharya", "Sikandarpur", t);
        addConnection("Sikandarpur", "MG Road", t);
        addConnection("MG Road", "IFFCO Chowk", t);
        addConnection("IFFCO Chowk", "Huda City Centre", t);
        
        // Blue Line Connections
        addConnection("Dwarka Sector 21", "Dwarka Sector 8", t);
        addConnection("Dwarka Sector 8", "Dwarka Sector 9", t);
        addConnection("Dwarka Sector 9", "Dwarka Sector 10", t);
        addConnection("Dwarka Sector 10", "Dwarka Sector 11", t);
        addConnection("Dwarka Sector 11", "Dwarka Sector 12", t);
        addConnection("Dwarka Sector 12", "Dwarka Sector 13", t);
        addConnection("Dwarka Sector 13", "Dwarka Sector 14", t);
        addConnection("Dwarka Sector 14", "Dwarka", t);
        addConnection("Dwarka", "Dwarka Mor", t);
        addConnection("Dwarka Mor", "Nawada", t);
        addConnection("Nawada", "Uttam Nagar West", t);
        addConnection("Uttam Nagar West", "Uttam Nagar East", t);
        addConnection("Uttam Nagar East", "Janakpuri West", t);
        addConnection("Janakpuri West", "Janakpuri East", t);
        addConnection("Janakpuri East", "Tilak Nagar", t);
        addConnection("Tilak Nagar", "Subhash Nagar", t);
        addConnection("Subhash Nagar", "Tagore Garden", t);
        addConnection("Tagore Garden", "Rajouri Garden", t);
        addConnection("Rajouri Garden", "Ramesh Nagar", t);
        addConnection("Ramesh Nagar", "Moti Nagar", t);
        addConnection("Moti Nagar", "Kirti Nagar", t);
        addConnection("Kirti Nagar", "Shadipur", t);
        addConnection("Shadipur", "Patel Nagar", t);
        addConnection("Patel Nagar", "Rajendra Place", t);
        addConnection("Rajendra Place", "Karol Bagh", t);
        addConnection("Karol Bagh", "Jhandewalan", t);
        addConnection("Jhandewalan", "RK Ashram Marg", t);
        addConnection("RK Ashram Marg", "Rajiv Chowk", t);
        addConnection("Rajiv Chowk", "Barakhamba Road", t);
        addConnection("Barakhamba Road", "Mandi House", t);
        addConnection("Mandi House", "Pragati Maidan", t);
        addConnection("Pragati Maidan", "Indraprastha", t);
        addConnection("Indraprastha", "Yamuna Bank", t);
        addConnection("Yamuna Bank", "Akshardham", t);
        addConnection("Akshardham", "Mayur Vihar I", t);
        addConnection("Mayur Vihar I", "Mayur Vihar Extension", t);
        addConnection("Mayur Vihar Extension", "New Ashok Nagar", t);
        addConnection("New Ashok Nagar", "Noida Sector 15", t);
        addConnection("Noida Sector 15", "Noida Sector 16", t);
        addConnection("Noida Sector 16", "Noida Sector 18", t);
        addConnection("Noida Sector 18", "Botanical Garden", t);
        
        // Additional connections would be formatted similarly for other lines.
        
        // Red Line Connections
        addConnection("Dilshad Garden", "Jhilmil", t);
        addConnection("Jhilmil", "Mansarovar Park", t);
        addConnection("Mansarovar Park", "Shahdara", t);
        addConnection("Shahdara", "Welcome", t);
        addConnection("Welcome", "Seelampur", t);
        addConnection("Seelampur", "Shastri Park", t);
        addConnection("Shastri Park", "Kashmere Gate", t);
        addConnection("Kashmere Gate", "Tis Hazari", t);
        addConnection("Tis Hazari", "Pul Bangash", t);
        addConnection("Pul Bangash", "Pratap Nagar", t);
        addConnection("Pratap Nagar", "Shastri Nagar", t);
        addConnection("Shastri Nagar", "Inderlok", t);
        addConnection("Inderlok", "Kanhaiya Nagar", t);
        addConnection("Kanhaiya Nagar", "Keshav Puram", t);
        addConnection("Keshav Puram", "Netaji Subhash Place", t);
        addConnection("Netaji Subhash Place", "Kohat Enclave", t);
        addConnection("Kohat Enclave", "Pitam Pura", t);
        addConnection("Pitam Pura", "Rohini East", t);
        addConnection("Rohini East", "Rohini West", t);
        addConnection("Rohini West", "Rithala", t);
        
        // Green Line Connections
        addConnection("Mundka", "Mundka Industrial Area", t);
        addConnection("Mundka Industrial Area", "Ghevra", t);
        addConnection("Ghevra", "Tikri Kalan", t);
        addConnection("Tikri Kalan", "Tikri Border", t);
        addConnection("Tikri Border", "Pandit Shree Ram Sharma", t);
        addConnection("Pandit Shree Ram Sharma", "Bahadurgarh City", t);
        addConnection("Bahadurgarh City", "Brigadier Hoshiyar Singh", t);
        addConnection("Brigadier Hoshiyar Singh", "Inderlok", t);
        addConnection("Inderlok", "Ashok Park Main", t);
        addConnection("Ashok Park Main", "Punjabi Bagh", t);
        addConnection("Punjabi Bagh", "Shivaji Park", t);
        addConnection("Shivaji Park", "Madipur", t);
        addConnection("Madipur", "Paschim Vihar East", t);
        addConnection("Paschim Vihar East", "Paschim Vihar West", t);
        addConnection("Paschim Vihar West", "Peera Garhi", t);
        addConnection("Peera Garhi", "Udyog Nagar", t);
        addConnection("Udyog Nagar", "Maharaja Surajmal Stadium", t);
        addConnection("Maharaja Surajmal Stadium", "Nangloi", t);
        addConnection("Nangloi", "Nangloi Railway station", t);
        addConnection("Nangloi Railway station", "Rajdhani Park", t);
        addConnection("Rajdhani Park", "Nangli", t);
        addConnection("Nangli", "Najafgarh", t);
        
        // Violet Line Connections
        addConnection("Kashmere Gate", "Lal Qila", t);
        addConnection("Lal Qila", "Jama Masjid", t);
        addConnection("Jama Masjid", "Delhi Gate", t);
        addConnection("Delhi Gate", "ITO", t);
        addConnection("ITO", "Mandi House", t);
        addConnection("Mandi House", "Janpath", t);
        addConnection("Janpath", "Central Secretariat", t);
        addConnection("Central Secretariat", "Khan Market", t);
        addConnection("Khan Market", "Jawaharlal Nehru Stadium", t);
        addConnection("Jawaharlal Nehru Stadium", "Jangpura", t);
        addConnection("Jangpura", "Lajpat Nagar", t);
        addConnection("Lajpat Nagar", "Moolchand", t);
        addConnection("Moolchand", "Kailash Colony", t);
        addConnection("Kailash Colony", "Nehru Place", t);
        addConnection("Nehru Place", "Kalkaji Mandir", t);
        addConnection("Kalkaji Mandir", "Govind Puri", t);
        addConnection("Govind Puri", "Okhla", t);
        addConnection("Okhla", "Jasola Apollo", t);
        addConnection("Jasola Apollo", "Sarita Vihar", t);
        addConnection("Sarita Vihar", "Mohan Estate", t);
        addConnection("Mohan Estate", "Tughlakabad", t);
        addConnection("Tughlakabad", "Badarpur Border", t);
        addConnection("Badarpur Border", "Sarai", t);
        addConnection("Sarai", "NHPC Chowk", t);
        addConnection("NHPC Chowk", "Mewala Maharajpur", t);
        addConnection("Mewala Maharajpur", "Sector 28", t);
        addConnection("Sector 28", "Badkal Mor", t);
        addConnection("Badkal Mor", "Old Faridabad", t);
        addConnection("Old Faridabad", "Neelam Chowk Ajronda", t);
        addConnection("Neelam Chowk Ajronda", "Bata Chowk", t);
        addConnection("Bata Chowk", "Escorts Mujesar", t);
        addConnection("Escorts Mujesar", "Raja Nahar Singh", t);
        
        // Magenta Line Connections
        addConnection("Botanical Garden", "Okhla Bird Sanctuary", t);
        addConnection("Okhla Bird Sanctuary", "Kalindi Kunj", t);
        addConnection("Kalindi Kunj", "Jasola Vihar Shaheen Bagh", t);
        addConnection("Jasola Vihar Shaheen Bagh", "Okhla NSIC", t);
        addConnection("Okhla NSIC", "Sukhdev Vihar", t);
        addConnection("Sukhdev Vihar", "Jamia Millia Islamia", t);
        addConnection("Jamia Millia Islamia", "Okhla Vihar", t);
        addConnection("Okhla Vihar", "Batla House", t);
        addConnection("Batla House", "Hazrat Nizamuddin", t);
        addConnection("Hazrat Nizamuddin", "Ashram", t);
        addConnection("Ashram", "Vinobapuri", t);
        addConnection("Vinobapuri", "Sarojini Nagar", t);
        addConnection("Sarojini Nagar", "Bhikaji Cama Place", t);
        addConnection("Bhikaji Cama Place", "Sir Vishweshwaraiah Moti Bagh", t);
        addConnection("Sir Vishweshwaraiah Moti Bagh", "Durgabai Deshmukh South Campus", t);
        addConnection("Durgabai Deshmukh South Campus", "Shankar Vihar", t);
        addConnection("Shankar Vihar", "Vasant Vihar", t);
        addConnection("Vasant Vihar", "Munirka", t);
        addConnection("Munirka", "R.K.Puram", t);
        addConnection("R.K.Puram", "IIT Delhi", t);
        addConnection("IIT Delhi", "Hauz Khas", t);
        
        // Pink Line Connections
        addConnection("Majlis Park", "Azadpur", t);
        addConnection("Azadpur", "Shalimar Bagh", t);
        addConnection("Shalimar Bagh", "Netaji Subhash Place", t);
        addConnection("Netaji Subhash Place", "Shakurpur", t);
        addConnection("Shakurpur", "Punjabi Bagh West", t);
        addConnection("Punjabi Bagh West", "ESI Hospital", t);
        addConnection("ESI Hospital", "Rajouri Garden", t);
        addConnection("Rajouri Garden", "Mayapuri", t);
        addConnection("Mayapuri", "Naraina Vihar", t);
        addConnection("Naraina Vihar", "Delhi Cantonment", t);
        addConnection("Delhi Cantonment", "Durgabai Deshmukh South Campus", t);
        addConnection("Durgabai Deshmukh South Campus", "Sir Vishweshwaraiah Moti Bagh", t);
        addConnection("Sir Vishweshwaraiah Moti Bagh", "Bhikaji Cama Place", t);
        addConnection("Bhikaji Cama Place", "Sarojini Nagar", t);
        addConnection("Sarojini Nagar", "INA", t);
        addConnection("INA", "South Extension", t);
        addConnection("South Extension", "Lajpat Nagar", t);
        addConnection("Lajpat Nagar", "Vinobapuri", t);
        addConnection("Vinobapuri", "Ashram", t);
        addConnection("Ashram", "Hazrat Nizamuddin", t);
        addConnection("Hazrat Nizamuddin", "Mayur Vihar Pocket I", t);
        addConnection("Mayur Vihar Pocket I", "Trilokpuri Sanjay Lake", t);
        addConnection("Trilokpuri Sanjay Lake", "East Vinod Nagar – Mayur Vihar-II", t);
        addConnection("East Vinod Nagar – Mayur Vihar-II", "Mandawali – West Vinod Nagar", t);
        addConnection("Mandawali – West Vinod Nagar", "IP Extension", t);
        addConnection("IP Extension", "Anand Vihar", t);
        addConnection("Anand Vihar", "Karkarduma", t);
        addConnection("Karkarduma", "Karkarduma Court", t);
        addConnection("Karkarduma Court", "Krishna Nagar", t);
        addConnection("Krishna Nagar", "East Azad Nagar", t);
        addConnection("East Azad Nagar", "Welcome", t);
        addConnection("Welcome", "Jaffrabad", t);
        addConnection("Jaffrabad", "Maujpur-Babarpur", t);
        addConnection("Maujpur-Babarpur", "Gokulpuri", t);
        addConnection("Gokulpuri", "Johari Enclave", t);
        addConnection("Johari Enclave", "Shiv Vihar", t);


    }
};

int main() {
    MetroSystem delhiMetro;
    delhiMetro.setupSystem();
    delhiMetro.dijkstra("Sarai", "Botanical Garden");

    return 0;
}