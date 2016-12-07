// bleeding - maximum possible bleeding rate for a given wound type (0 .. 1)
// pain - maximum possible pain level for a given wound type (0 .. 1)

class ACE_Medical_Injuries {
    // Defines all the possible injury types
    class wounds {
        // Source: Scarle
        //  Also called scrapes, they occur when the skin is rubbed away by friction against another rough surface (e.g. rope burns and skinned knees).
        class Abrasion {
            name = CSTRING(Abrasion);
            causes[] = {"falling", "ropeburn", "vehiclecrash", "unknown"};
            bleeding = 0.001;
            pain = 0.4;
            minDamage = 0.01;
            maxDamage = 0.30;
        };
        // Occur when an entire structure or part of it is forcibly pulled away, such as the loss of a permanent tooth or an ear lobe. Explosions, gunshots, and animal bites may cause avulsions.
        class Avulsions {
            name = CSTRING(Avulsion);
            causes[] = {"explosive", "vehiclecrash", "grenade", "shell", "bullet", "backblast", "bite"};
            bleeding = 0.5;
            pain = 1.0;
            minDamage = 0.01;
            causeLimping = 1;
        };
        // Also called bruises, these are the result of a forceful trauma that injures an internal structure without breaking the skin. Blows to the chest, abdomen, or head with a blunt instrument (e.g. a football or a fist) can cause contusions.
        class Contusion {
            name = CSTRING(Contusion);
            causes[] = {"bullet", "backblast", "punch", "vehiclecrash", "falling"};
            bleeding = 0.0;
            pain = 0.3;
            minDamage = 0.02;
            maxDamage = 0.35;
        };
        // Occur when a heavy object falls onto a person, splitting the skin and shattering or tearing underlying structures.
        class CrushWound {
            name = CSTRING(Crush);
            causes[] = {"falling", "vehiclecrash", "punch", "unknown"};
            bleeding = 0.1;
            pain = 0.8;
            minDamage = 0.1;
            causeLimping = 1;
        };
        // Slicing wounds made with a sharp instrument, leaving even edges. They may be as minimal as a paper cut or as significant as a surgical incision.
        class Cut {
            name = CSTRING(Cut);
            causes[] = {"vehiclecrash", "grenade", "explosive", "shell", "backblast", "stab", "unknown"};
            bleeding = 0.04;
            pain = 0.1;
            minDamage = 0.1;
        };
        // Also called tears, these are separating wounds that produce ragged edges. They are produced by a tremendous force against the body, either from an internal source as in childbirth, or from an external source like a punch.
        class Laceration {
            name = CSTRING(Laceration);
            selections[] = {"All"};
            causes[] = {"vehiclecrash", "punch"};
            bleeding = 0.05;
            pain = 0.2;
            minDamage = 0.01;
        };
        // Also called velocity wounds, they are caused by an object entering the body at a high speed, typically a bullet or small peices of shrapnel.
        class velocityWound {
            name = CSTRING(VelocityWound);
            causes[] = {"bullet", "grenade","explosive", "shell", "unknown"};
            bleeding = 1.0;
            pain = 0.9;
            minDamage = 0.35;
            causeLimping = 1;
        };
        // Deep, narrow wounds produced by sharp objects such as nails, knives, and broken glass.
        class punctureWound {
            name = CSTRING(PunctureWound);
            causes[] = {"stab", "grenade"};
            bleeding = 0.1;
            pain = 0.4;
            minDamage = 0.02;
            causeLimping = 1;
        };
    };
    class damageTypes {
        // thresholds[] {{<min damage>, <max number of wounds>}, {...}}
        thresholds[] = {{0.1, 1}};
        selectionSpecific = 1;

        class bullet {
            // above damage, amount. Put the highest threshold to the left and lower the threshold with the elements to the right of it.
            thresholds[] = {{0.1, 1}};
            selectionSpecific = 1;
        };
        class grenade {
            thresholds[] = {{0.1, 3}, {0, 1}};
            selectionSpecific = 0;
        };
        class explosive {
            thresholds[] = {{1, 6}, {0.1, 4}, {0, 1}};
            selectionSpecific = 0;
        };
        class shell {
            thresholds[] = {{1, 7}, {0.1, 5}, {0, 1}};
            selectionSpecific = 0;
        };
        class vehiclecrash {
            thresholds[] = {{0.5, 5}, {0.3, 2}, {0.05, 1}};
            selectionSpecific = 0;
        };
        class backblast {
            thresholds[] = {{1, 6}, {0.55, 5}, {0, 2}};
            selectionSpecific = 0;
        };
        class stab {
            thresholds[] = {{0.1, 1}};
            selectionSpecific = 1;
        };
        class punch {
            thresholds[] = {{0.1, 1}};
            selectionSpecific = 1;
        };
        class falling {
            thresholds[] = {{0.6, 4}, {0.35, 2}, {0.1, 1}};
            selectionSpecific = 1;
        };
        class ropeburn {
            thresholds[] = {{0.1, 1}};
            selectionSpecific = 1;
        };
        class unknown {
            thresholds[] = {{0.1, 1}};
        };
    };
};
