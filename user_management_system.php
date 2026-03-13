<?php
/**
 * Advanced User Management System (Logic Only)
 * Focus: Security, Roles, and Data Validation
 */

class User {
    private $username;
    private $role;
    private $is_active;

    public function __construct($username, $role = 'User') {
        $this->username = $username;
        $this->role = $role;
        $this->is_active = true;
    }

    public function getRole() {
        return $this->role;
    }

    public function getUsername() {
        return $this->username;
    }
}

class AdminSystem {
    private $users = [];

    public function addUser(User $user) {
        $this->users[] = $user;
        echo "[System]: User '{$user->getUsername()}' added successfully.\n";
    }

    public function accessSensitiveData(User $user) {
        echo "--- Security Check for '{$user->getUsername()}' ---\n";
        
        // التحقق من الصلاحيات: الأدمن فقط يمكنه رؤية البيانات الحساسة
        if ($user->getRole() === 'Admin') {
            echo "Access GRANTED: Displaying sensitive financial data...\n";
            echo "Data: [Internal Revenue: $1,250,000 | Server Status: Stable]\n";
        } else {
            echo "Access DENIED: You do not have 'Admin' privileges.\n";
        }
        echo "-------------------------------------------\n\n";
    }
}

// --- تطبيق النظام (Simulation) ---

$system = new AdminSystem();

// إنشاء مستخدمين بصلاحيات مختلفة
$user1 = new User("Hossam_Admin", "Admin");
$user2 = new User("Guest_User", "Staff");

// محاولة الوصول للبيانات
$system->addUser($user1);
$system->accessSensitiveData($user1);

$system->addUser($user2);
$system->accessSensitiveData($user2);

?>
