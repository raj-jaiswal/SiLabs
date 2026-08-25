# Hospital Triage Auth & Admin Dispatch Sidebar Specification

> **Date:** 2026-08-23  
> **Project:** SiLabs Hospital Triage & Vital Sign Monitoring System  
> **Target App:** Next.js 14 (`triage_app`)  

---

## 1. Executive Summary

This design specification details the authentication system, user management, admin control panel, and admin-to-user patient dispatch notification system for the hospital triage dashboard.

Key capabilities:
1. **Simple Authentication**: Support for 1 Admin and multiple Users (`User 1`, `User 2`, `User 3`) with simple credentials.
2. **Admin Sidebar & User Tracker**: Admin can view active user sessions, registered user credentials, and add new users dynamically.
3. **Admin Patient Dispatch System**: Admin can assign/notify a specific user to attend to a specific patient with an urgent clinical note.
4. **User Notification Toast**: Logged-in staff users receive real-time notification alerts directing them to their assigned patient.

---

## 2. Default User Accounts (Simple Credentials)

| Role | Name | Email | Password |
| :--- | :--- | :--- | :--- |
| **Admin** | `Admin` | `admin@hospital.com` | `admin` |
| **Staff User 1** | `User 1` | `user1@hospital.com` | `user1` |
| **Staff User 2** | `User 2` | `user2@hospital.com` | `user2` |
| **Staff User 3** | `User 3` | `user3@hospital.com` | `user3` |

Users and credentials are stored in `localStorage` so Admin-added users persist across browser refreshes.

---

## 3. Component Architecture & Data Flow

1. **`src/context/AuthContext.tsx`**:
   - Manages `currentUser`, `users` list, `activeSessions`, and `dispatchedAssignments`.
   - Methods: `login(email, password)`, `logout()`, `addUser(name, email, password)`, `dispatchUserToPatient(userId, patientId, note)`, `acknowledgeAssignment(assignmentId)`.

2. **`src/components/LoginPage.tsx`**:
   - Simple login form with 1-click quick login buttons for `Admin`, `User 1`, `User 2`, `User 3`.

3. **`src/components/AdminSidebar.tsx`**:
   - Collapsible panel accessible when logged in as `Admin`.
   - **Active Session Monitor**: Shows currently logged-in user and timestamp.
   - **Add New User Form**: Input fields for Name, Email, Password.
   - **User Directory**: List of registered users and passwords.
   - **Patient Dispatch Console**: Select staff user + select patient ID + enter urgent note.

4. **`src/components/DispatchNotificationModal.tsx`**:
   - Pop-up alert for staff users when Admin assigns them to a patient.
   - Displays assigned patient ID, admin note, and `Inspect Patient` button.

---

## 4. Verification Criteria

1. Verify login works for Admin and all Users.
2. Verify Admin sidebar displays active user and allows adding new users with custom passwords.
3. Verify Admin can dispatch a user to a patient, and that user receives the notification banner.
4. Verify Next.js production build passes with zero TypeScript errors.
