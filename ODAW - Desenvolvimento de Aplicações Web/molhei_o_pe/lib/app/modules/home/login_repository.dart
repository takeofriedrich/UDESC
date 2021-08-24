import 'package:cloud_firestore/cloud_firestore.dart';
import 'package:firebase_auth/firebase_auth.dart';

class LoginRepository {
  Future<UserCredential> signInWithGoogle() async {
    // Create a new provider
    GoogleAuthProvider googleProvider = GoogleAuthProvider();

    googleProvider
        .addScope('https://www.googleapis.com/auth/contacts.readonly');
    googleProvider.setCustomParameters({'login_hint': 'user@example.com'});

    return await FirebaseAuth.instance.signInWithPopup(googleProvider);
  }

  loginFirestore(User user) async {
    DocumentReference docUser =
        FirebaseFirestore.instance.collection('users').doc(user.email);
    if (!(await docUser.get()).exists) {
      docUser.set({
        'nome': user.displayName,
        'foto': user.photoURL,
        'ocorrencias': 0,
      });
    }
  }
}
