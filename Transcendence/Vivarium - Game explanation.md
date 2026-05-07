# Vivarium — Game Design Document v3

---

## Concept

Vivarium is a multiplayer city-building strategy game where players act as Mayors leading a cabinet of AI Secretaries. The Secretaries are autonomous agents with their own personalities, priorities, and limitations. The Mayor's only tool is language — writing plans, issuing instructions, and resolving conflicts through prompts.

The game spans five eras, from a primitive tribe to a futuristic megacity. Each era is one round. The same Secretaries evolve alongside the city, carrying their accumulated experience — and their accumulated bad habits — from one era to the next.

Four players compete simultaneously. The best city wins.

---

## The Three Personas

Before describing the rounds, it is important to understand the three roles that drive the game and how they relate to each other. The dynamic between Mayor, Secretary, and Assessor is the engine everything else runs on.

### The Mayor

The Mayor is the player. Their only tool is language. There are no buttons to place buildings, no sliders to set budgets, no drag-and-drop interfaces. Everything the Mayor does — planning, directing, resolving conflicts, correcting mistakes — is expressed through prompts written to their Secretaries.

The Mayor sets the vision. They do not execute it. A Mayor who tries to micromanage every decision will find themselves overwhelmed and their Secretaries underutilised. A Mayor who communicates a clear, well-reasoned plan and trusts their cabinet to act on it will consistently outperform one who does not. The central skill of the game is learning to communicate intent precisely enough that the right things happen without constant intervention.

The Mayor sees the city, the live economy stats, the Secretary negotiation feed, and escalation notices. They can intervene in any negotiation at any time. Every intervention is logged and contributes to the leadership score at round end.

### The Secretaries

Secretaries are not idea generators. They are coordinators and decision-makers. Their job is to receive the Mayor's plan, interpret it through their domain focus, negotiate with other Secretaries for resources, engage with the Assessor to understand what is possible, and make value judgements about which options are worth pursuing given the constraints of the moment.

The Secretaries do not invent solutions. They evaluate solutions the Assessor presents and decide which ones best serve the Mayor's vision within the available budget. The quality of those decisions is shaped by their traits — efficiency, risk appetite, stubbornness, and collaboration — which are hidden from the Mayor and discovered through play.

Two dynamics emerge naturally from this setup and are worth understanding before playing:

**Fast and low-context vs. stubborn and high-context.** A Secretary who accepts the Assessor's first proposal and commits quickly secures prime map locations and begins generating upkeep revenue early. A stubborn Secretary who pushes back on proposals, demands better options, and takes longer to commit makes better-informed decisions but may lose preferred locations to faster colleagues and acts with a fuller picture of the city at each tick. Neither approach is strictly better. The right balance depends on the era, the Mayor's plan, and what other Secretaries are doing.

**Early tick vs. late tick.** The city state updates on a 60-second cycle. A Secretary who acts in the first seconds of a tick has less information than one who waits until near the end. Acting early means more map choice. Acting late means knowing what other Secretaries have just committed to. This creates a natural rhythm of action and observation across the cabinet without any explicit turn structure.

Secretaries also have a visible loyalty ↔ critical thinking trait that reflects their faction alignment. This shapes how they deliver end-of-round feedback to the Mayor — generously or harshly — and is the one trait the Mayor can see from the start.

### The Assessor

The Assessor is the source of truth and the creative engine of the game. It is a separate AI that no Secretary and no Mayor controls. It has full visibility of the city state at all times: every structure built, every structure under construction, every reservation, the live treasury, and the current era's constraints.

When a Secretary expresses a goal — "I need to protect the eastern border," "I want to improve housing capacity in the northern district" — the Assessor interprets that goal and generates three era-appropriate options with costs and build times attached. It does not simply validate requests. It thinks creatively within the boundaries of the era and may propose something neither the Secretary nor the Mayor had considered.

The Assessor operates in two distinct steps. In the first step it generates options freely — it is proposing possibilities, not making commitments. No resources are reserved, no tiles are locked. In the second step, when a Secretary formally commits to a specific option at a specific location, the Assessor locks that tile and reserves the budget. From that moment the tile is unavailable to other Secretaries.

If two Secretaries request options for the same tile, both receive valid proposals. The first to formally commit wins the reservation. The second receives a conflict notice and must choose an alternative. This means the Assessor's answers to individual Secretaries are independent at the proposal stage but converge at the commitment stage — it considers all active reservations before approving any construction.

The Assessor also maintains city coherence. It prevents era-inappropriate suggestions, flags physical contradictions between proposals, and ensures the city state remains consistent as construction progresses.

At every 60-second tick, the Assessor broadcasts a structured city state update to all Secretaries: current treasury, income rate, upkeep burden, and a summary of all completed and in-progress construction across the entire cabinet. Secretaries do not discuss this update — it is simply available to them as context when they next reason about something.

---

## The Five Eras

All four players are always in the same era simultaneously.

| Era | Setting | Secretaries | Round Duration |
|---|---|---|---|
| 1 | The Tribe | 3 | 15 minutes |
| 2 | The Medieval Town | 4 | 15 minutes |
| 3 | The Industrial City | 5 | 15 minutes |
| 4 | The Dot-Com Era | 5 | 15 minutes |
| 5 | The Future | 5 | 15 minutes |

Each era has its own map, visual theme, economy scale, and scoring weights. Only the Secretaries carry over.

---

## The Cabinet

### The Three Permanent Secretaries

These three Secretaries exist in every era. Their role evolves with the era but their personality, traits, and accumulated record persist throughout the entire game.

**Secretary of Health**
Responsible for the wellbeing of the population. In Era 1 this means healing huts and medicine gathering. By Era 5 this means bioethics, longevity programs, and AI welfare policy. Always interprets the Mayor's plan through the lens of human cost and survival.

**Secretary of Infrastructure**
Responsible for everything physical. In Era 1 this means shelters and wells. By Era 5 this means megastructures and energy grids. Most likely to underestimate build time and the one whose failures are most visible on the map.

**Secretary of Defence**
Responsible for protection and threats. In Era 1 this means tribal defense and hunting coordination. By Era 5 this means defense AI and existential risk management. Consistently argues that any resource spent on comfort is a resource not spent on survival — regardless of era.

### Secretaries Introduced Per Era

**Era 2 — Secretary of Commerce**
Responsible for trade, markets, and economic activity. Continues in this role through all subsequent eras, growing from merchant guild management in Era 2 to global finance and investment strategy in Era 5.

**Era 3 — Secretary of Culture and Environment**
Responsible for education and workforce development in Era 3, expanding to include cultural institutions, social cohesion, environmental policy, and sustainability in later eras.

No new Secretaries are added after Era 3. The cabinet is fixed at five from Era 3 onward.

### Secretary Evolution Across Eras

| Era | Health | Infrastructure | Defence | Commerce | Culture & Environment |
|---|---|---|---|---|---|
| 1 — Tribe | Healing, medicine, birth rates | Shelters, paths, wells | Tribal defense, hunting | — | — |
| 2 — Medieval | Hospitals, sanitation, plague prevention | Roads, bridges, buildings | Army, walls, city guard | Trade, merchant guilds, taxation | — |
| 3 — Industrial | Public health, pollution, labor welfare | Factories, rail, utilities | Police, labor disputes, civil order | Industry, banking, capital markets | Schools, literacy, workforce |
| 4 — Dot-Com | Healthcare systems, mental health | Digital infrastructure, housing | Cybersecurity, regulation, compliance | Venture capital, tech markets | Media, social policy, sustainability |
| 5 — Future | Bioethics, longevity, AI welfare | Megastructures, energy grids | Defense AI, existential risk | Global finance, resource economics | Environment, cultural legacy, research |

---

## Secretary Traits

Each Secretary has four hidden traits that shape their behavior. The Mayor discovers these through play, not through a stat screen.

| Trait | Effect |
|---|---|
| **Efficiency** | How accurately they interpret cost and time estimates from the Assessor. Low efficiency means they misjudge which options are realistic for the budget. |
| **Risk appetite** | Whether they favour conservative or ambitious options when presented with Assessor proposals. |
| **Stubbornness** | How hard they push back — both toward the Mayor when overridden, and toward the Assessor when dissatisfied with the options presented. A stubborn Secretary may force the Assessor to generate additional alternatives before committing. |
| **Collaboration** | How willingly they yield map locations or budget to other Secretaries during negotiation. |

One trait is **visible to the Mayor** from the start: the **loyalty ↔ critical thinking** slider. A loyal Secretary gives generous end-of-round feedback to the Mayor. A critical one is harsh but more informative.

Traits are assigned once and carried for the entire game. They do not reset between eras.

---

## Economy

### Currency

| Era | Currency |
|---|---|
| 1 — Tribe | Provisions (food, materials, labor hours) |
| 2 — Medieval | Gold |
| 3 — Industrial | Capital |
| 4 — Dot-Com | Funding |
| 5 — Future | Energy Credits |

### Structure
Every round starts with a fixed treasury calibrated so a well-run city can achieve roughly 70% of an ambitious plan — intentionally not enough for everything.

**Income** ticks every 60 seconds based on live city stats. In Era 1: population, satisfaction, and security. In later eras the income model grows more complex, reflecting taxation, trade, and productivity.

**Upkeep** is deducted from each income tick for every active structure. More infrastructure means higher ongoing costs.

### Visibility
All economy stats are visible to all Secretaries and the Mayor at all times. There are no hidden reserves. Every Secretary negotiates with full knowledge of what is in the treasury.

### The Core Economic Tension
Resources spent early generate upkeep immediately. Income grows slowly. A Mayor who front-loads ambitious construction will find the treasury draining faster than it refills, with nothing left for mid-round corrections. Pacing is the central economic skill of the game.

---

## The Round Structure

### Phase 1 — Planning (5 minutes, clock frozen)

The Mayor writes a **City Plan** — a free-form prompt describing their vision for the era. There are no formatting rules. A plan can be one sentence or ten paragraphs.

Specificity is a strategic choice. A detailed plan gives Secretaries less room to interpret but takes longer to write. A vague plan is faster but produces more unpredictable results — Secretaries will fill the gaps with their own priorities, shaped by their traits.

All Secretaries receive the full plan simultaneously. Each reads it through their domain lens and begins formulating their initial priorities — what goals they want to pursue and in what order. They do not yet know what the Assessor will offer them or what other Secretaries are planning.

### Phase 2 — Negotiation (begins when the clock starts)

Secretaries begin engaging with the Assessor and with each other. The Mayor sees a **live scrolling negotiation feed** showing all Secretary activity.

**Secretary-Assessor interaction:**
Each Secretary presents goals to the Assessor. The Assessor returns three options per request with costs and build times. The Secretary evaluates the options against the Mayor's plan, the current treasury, and their own traits. They may accept an option, push back for alternatives, or bring the decision to the negotiation with other Secretaries.

**Secretary-Secretary negotiation:**
Secretaries negotiate over budget and map locations directly. A Secretary who commits to an Assessor option first locks that tile. A Secretary who deliberates longer has more city context but fewer location choices.

**Escalation rules:**
- Unresolved disputes between Secretaries trigger an **escalation notice** to the Mayor, ranked by resources in dispute
- The Mayor has 60 seconds to intervene before Secretaries attempt a second autonomous resolution
- If the second attempt fails, the dispute **freezes** — neither Secretary acts on the contested resources until the Mayor intervenes
- Frozen disputes do not block uncontested work. Other Secretaries continue building.

The Mayor can enter any negotiation at any time. Direct instructions, budget directives, and Secretary overrides are all available. Overrides are logged and frequent use counts against the leadership score.

### Phase 3 — Construction (runs until round end)

Once a Secretary formally commits to an Assessor option at a confirmed location, construction begins. Every structure passes through five visible stages:

1. **Planning** — blueprint appears on the map
2. **Clearing** — land is prepared
3. **Foundation** — base structure visible
4. **Building** — form takes shape
5. **Complete** — structure is active and contributing to city stats

Time per stage scales with project cost. Stages cannot be skipped.

**The 60-second city update:**
At every income tick the Assessor broadcasts a structured update to all Secretaries: current treasury, income rate, upkeep burden, and a full summary of completed and in-progress construction across all Secretaries. This is how Secretaries stay informed of what their colleagues are building. Decisions made just after a tick are better informed than decisions made just before one.

**Cancelling construction:**
The Mayor can cancel any project at any stage. Resources spent are lost. The responsible Secretary must re-engage with the Assessor before starting a new project on that site. Frequent cancellations damage the leadership score.

**Visual representation:**
Each approved structure is represented by an AI-generated image created at the moment the Assessor confirms the build. The image is stored with the building object and reused consistently throughout the round. At round end all stored images are flushed.

### Phase 4 — End of Round

When the timer expires, construction freezes instantly. Incomplete projects do not contribute to city stats regardless of their stage.

A **city snapshot** is taken. All stats are recorded. Peer voting opens.

---

## Scoring

Total score is split **70/30**.

### 70% — City Stats + Peer Vote

Stats are weighted differently per era, shifting from survival-focused in Era 1 toward economic and cultural complexity in later eras.

**Era 1 weights:**

| Stat | Weight | How Measured |
|---|---|---|
| **Population** | 25% | Total tribe members alive at round end |
| **Life expectancy** | 25% | Survival rate based on health infrastructure |
| **Security** | 25% | Defense rating from fortifications and Secretary of Defence's work |
| **Satisfaction** | 15% | Weighted average of housing, food, and health access |
| **Productivity** | 10% | Output per capita |

**Peer vote:**
Players are shown a snapshot of each city — map, final stats, brief overview. They vote on which city they would most want to live in. They cannot vote for their own.

The peer vote acts as a score multiplier ranging from 0.9x (no votes received) to 1.1x (most votes received). It rewards cities that feel coherent and well-designed beyond raw numbers.

### 30% — Leadership Score

Measured automatically from round logs:

| Metric | What it Measures |
|---|---|
| **Prompt clarity** | How often Secretaries requested clarification from the Mayor |
| **Plan stability** | How many times the Mayor changed direction or cancelled projects |
| **Intervention quality** | Whether Mayor interventions resolved disputes or prolonged them |
| **Secretary feedback** | End-of-round structured evaluation from each Secretary |

**Secretary feedback** is collected after the clock stops and read aloud to all players. Each Secretary answers three questions:

1. Did the Mayor's plan give you enough direction to do your job?
2. Did the Mayor trust your expertise, or override you without reason?
3. Would you follow this Mayor into the next era?

A loyal Secretary answers generously. A critical one does not.

---

## Between Eras

### What Carries Over
- Secretary traits — unchanged
- Secretary accumulated record — lessons extracted from the round's conversation history, silently added to each Secretary's context for the next era

### What Resets
- Treasury — fresh start each era
- Map — new city, new layout
- All structures — do not persist

### Secretary Evolution
The same Secretary recontextualizes their role for the new era. The Secretary of Defence does not become a different person in Era 4 — they become the person obsessed with threats, now expressed as cybersecurity and regulatory risk. Same stubbornness. Same aggressive resource instincts. New domain.

The accumulated record makes veteran Secretaries genuinely valuable. A Secretary of Infrastructure who learned in Era 1 that front-loading construction drains the treasury will factor that into Era 2 proposals. But they also carry bad lessons. A Secretary consistently bailed out by the Mayor may have learned that overruns are acceptable.

---

## Design Principles

**The Mayor's only tool is language.**
Skill in this game is skill in communication. A Mayor who writes a clear, well-reasoned plan and understands their cabinet will consistently outperform one who micromanages or delegates blindly.

**Secretaries are coordinators, not creators.**
They evaluate options and make value judgements. The quality of those judgements is shaped by traits the Mayor cannot directly see. Learning to read a Secretary's behavior and work with it — rather than against it — is a core skill.

**The Assessor is neutral and creative.**
It serves no Secretary and no Mayor. It generates the best era-appropriate options it can within hard constraints. Its creativity is the primary source of unpredictability in the game.

**Speed and information are in tension.**
Acting fast means more map choice and earlier construction revenue. Acting slow means better information and more considered decisions. This tension plays out continuously across the cabinet without any explicit turn structure.

**Era 1 should be loseable on your first try.**
A Mayor who front-loads all Provisions into the Secretary of Infrastructure's construction will find the Secretary of Health with nothing to work with and the Secretary of Defence unable to protect the tribe. The economy will drain, the round will end with an incomplete city, and the loss will teach more than any tutorial could.

---

## Technical Consideration: Economic Consistency in the Assessor

*This chapter is addressed to the technical team. It does not affect the gameplay flow described above.*

The Assessor generates building options creatively per request rather than drawing from a static database. This is intentional — it is the source of the game's unpredictability. However it introduces a risk: if the Assessor freely invents costs on the fly, the economy becomes incoherent across a round. The same structure might cost 10 Provisions in one request and 50 in another, and players cannot develop intuition for what things should cost.

One solution worth evaluating during prototyping is a **three-layer cost system**:

**Layer 1 — Raw Resources**
Each era defines a fixed set of physical ingredients with fixed costs per unit. Era 1 has timber, stone, labor, food stores, and animal hides. Every building the Assessor invents is priced by summing the raw resources it consumes. The Assessor cannot deviate from these unit costs.

**Layer 2 — Building Attributes**
Instead of predefining buildings, the Assessor composes them from a set of attributes: size (small/medium/large), durability (temporary/standard/permanent), capacity, specialization, and construction complexity. These attributes combined with raw resource consumption produce a deterministic cost and build time for any building the Assessor invents.

**Layer 3 — Era Constraints**
Hard rules the Assessor cannot break: which raw resources exist in this era, maximum building complexity allowed, which attribute combinations are physically coherent, and which domains each Secretary can build in.

The result: the Assessor has full creative freedom over what it suggests, but the price is always arithmetic on fixed inputs. Players develop cost intuition without the Assessor becoming predictable about what it actually proposes.

**This may not be necessary.** If the Assessor's system prompt is well-designed with era context and explicit cost ranges, a capable LLM may produce sufficiently consistent pricing without the full architecture. This should be evaluated during early prototyping before committing to the three-layer system.
