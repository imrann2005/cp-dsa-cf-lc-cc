// Multi-Constraint Shortest Path using Dynamic Programming (Label-Setting DP)
// Objective: minimize latency, satisfy bandwidth >= F, minimize cost as tie-breaker
// Works directly in any online compiler — no input file needed.

#include <bits/stdc++.h>
using namespace std;

struct Edge {
    int to;
    int latency;
    int bandwidth;
    int cost;
    int id;
};

struct LabelFull {
    int node;
    long long latency;
    int bandwidth;
    long long cost;
    int pred_label_id;
    int via_edge_id;
};

struct LabelMeta {
    long long latency;
    long long cost;
    int bandwidth;
    int master_id;
};

int main() {
    ios::sync_with_stdio(false);
    cin.tie(nullptr);

    cout << "=== Multi-Constraint Shortest Path (Dynamic Programming) ===\n";
    cout << "Using built-in example network (A=0..E=4)\n\n";

    // Example network:
    // Nodes: A=0, B=1, C=2, D=3, E=4
    // Edges: (u v latency bandwidth cost)
    // File size requirement F = 6 (so bandwidth >= 6)
    int N = 5;
    int S = 0, D = 4, F = 6;

    vector<vector<Edge>> g(N);
    vector<Edge> edge_list_by_id;

    // --- Network definition ---
    // A->B (0->1)
    edge_list_by_id.push_back({1, 2, 6, 3, 0});
    g[0].push_back(edge_list_by_id.back());
    // B->C (1->2)
    edge_list_by_id.push_back({2, 4, 10, 2, 1});
    g[1].push_back(edge_list_by_id.back());
    // A->D (0->3)
    edge_list_by_id.push_back({3, 3, 7, 1, 2});
    g[0].push_back(edge_list_by_id.back());
    // D->C (3->2)
    edge_list_by_id.push_back({2, 2, 6, 2, 3});
    g[3].push_back(edge_list_by_id.back());
    // C->E (2->4)
    edge_list_by_id.push_back({4, 5, 8, 2, 4});
    g[2].push_back(edge_list_by_id.back());

    cout << "Network edges:\n";
    cout << "u -> v   latency  bandwidth  cost\n";
    for (int u = 0; u < N; ++u) {
        for (auto &e : g[u]) {
            cout << u << " -> " << e.to << "    " << e.latency
                 << "         " << e.bandwidth
                 << "          " << e.cost << "\n";
        }
    }
    cout << "\nSource = " << S << " (A), Destination = " << D
         << " (E), Required Bandwidth >= " << F << "\n\n";

    // === DP Label-Setting Algorithm ===

    vector<LabelFull> master;
    vector<vector<LabelMeta>> labels_at_node(N);

    struct PQEntry {
        long long latency;
        long long cost;
        int master_id;
        bool operator<(PQEntry const &other) const {
            if (latency != other.latency) return latency > other.latency;
            return cost > other.cost;
        }
    };
    priority_queue<PQEntry> pq;

    // Initial label
    LabelFull init{S, 0, INT_MAX, 0, -1, -1};
    master.push_back(init);
    labels_at_node[S].push_back({0, 0, INT_MAX, 0});
    pq.push({0, 0, 0});

    bool found_any_feasible = false;
    long long best_feasible_latency = LLONG_MAX;
    size_t expansions = 0;

    const size_t MAX_EXP = 1'000'000;

    while (!pq.empty()) {
        auto top = pq.top();
        pq.pop();
        int lid = top.master_id;
        const auto &L = master[lid];
        expansions++;

        // Early stop if dominated by known feasible
        if (found_any_feasible && L.latency > best_feasible_latency) break;

        // If at destination and meets constraint
        if (L.node == D && L.bandwidth >= F) {
            found_any_feasible = true;
            best_feasible_latency = min(best_feasible_latency, L.latency);
            continue;
        }

        // Expand along outgoing edges
        for (auto &e : g[L.node]) {
            LabelFull newL;
            newL.node = e.to;
            newL.latency = L.latency + e.latency;
            newL.bandwidth = min(L.bandwidth, e.bandwidth);
            newL.cost = L.cost + e.cost;
            newL.pred_label_id = lid;
            newL.via_edge_id = e.id;

            if (found_any_feasible && newL.latency > best_feasible_latency) continue;

            bool reject = false;
            vector<int> dominated;
            int idx = 0;
            for (auto &m : labels_at_node[e.to]) {
                if (m.latency <= newL.latency && m.cost <= newL.cost && m.bandwidth >= newL.bandwidth) {
                    bool strict = (m.latency < newL.latency) || (m.cost < newL.cost) || (m.bandwidth > newL.bandwidth);
                    if (strict) {
                        reject = true;
                        break;
                    }
                }
                if (newL.latency <= m.latency && newL.cost <= m.cost && newL.bandwidth >= m.bandwidth) {
                    bool strict = (newL.latency < m.latency) || (newL.cost < m.cost) || (newL.bandwidth > m.bandwidth);
                    if (strict) dominated.push_back(idx);
                }
                idx++;
            }
            if (reject) continue;

            int newId = (int)master.size();
            master.push_back(newL);

            if (!dominated.empty()) {
                vector<LabelMeta> nv;
                for (int i = 0; i < (int)labels_at_node[e.to].size(); i++) {
                    if (find(dominated.begin(), dominated.end(), i) == dominated.end())
                        nv.push_back(labels_at_node[e.to][i]);
                }
                labels_at_node[e.to].swap(nv);
            }

            labels_at_node[e.to].push_back({newL.latency, newL.cost, newL.bandwidth, newId});
            pq.push({newL.latency, newL.cost, newId});
        }

        if (expansions > MAX_EXP) {
            cerr << "Terminated early to prevent explosion of labels.\n";
            break;
        }
    }

    // Collect feasible
    vector<int> feasible_ids;
    for (auto &m : labels_at_node[D])
        if (m.bandwidth >= F) feasible_ids.push_back(m.master_id);

    if (feasible_ids.empty()) {
        cout << "No feasible path found.\n";
        return 0;
    }

    long long best_latency = LLONG_MAX, best_cost = LLONG_MAX;
    int best_id = -1;
    for (int id : feasible_ids) {
        auto &L = master[id];
        if (L.latency < best_latency ||
            (L.latency == best_latency && L.cost < best_cost)) {
            best_latency = L.latency;
            best_cost = L.cost;
            best_id = id;
        }
    }

    vector<int> path;
    for (int cur = best_id; cur != -1; cur = master[cur].pred_label_id)
        path.push_back(master[cur].node);
    reverse(path.begin(), path.end());

    cout << "✅ Optimal path found!\n";
    cout << "Latency = " << master[best_id].latency
         << ", Cost = " << master[best_id].cost
         << ", Path Bandwidth = " << master[best_id].bandwidth << "\n";
    cout << "Path nodes: ";
    for (size_t i = 0; i < path.size(); i++)
        cout << path[i] << (i + 1 < path.size() ? " -> " : "\n");

    cout << "\nEdge sequence (u->v [lat,bw,cost]):\n";
    for (size_t i = 0; i + 1 < path.size(); i++) {
        int u = path[i], v = path[i + 1];
        for (auto &e : g[u])
            if (e.to == v)
                cout << u << "->" << v << " [" << e.latency << "," << e.bandwidth << "," << e.cost << "]\n";
    }

    cout << "\nTotal label expansions: " << expansions << ", labels stored: " << master.size() << "\n";
    return 0;
}